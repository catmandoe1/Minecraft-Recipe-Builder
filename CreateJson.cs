using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MC_Recipe_Builder {
    internal class CreateData {
        public int Count { get; set; }
        public bool IsAdvanced { get; set; }
        public string Filename { get; set; }
        public CreateDataItem Result { get; set; }
        //public string AdResult { get; set; }
        public string Type { get; set; }

        public List<CreateDataItem> Data { get; set; }
        //public List<string> Data { get; set; }
        //public List<string> AdvancedData { get; set; }
        //public List<bool> CheckData { get; set; }

        public bool HasCheck(int start) {
            if (Data == null) return false;
            if (Data.Count < 9) return false;
            if (string.IsNullOrEmpty(Data[start].Name) && string.IsNullOrEmpty(Data[start + 1].Name) && string.IsNullOrEmpty(Data[start + 2].Name)) return false;
            return true;
        }

        public bool IsValid() {
            if (Data == null) return false;
            if (Data.Count < 9) return false;
            if(string.IsNullOrEmpty(Filename)) return false;
            if(string.IsNullOrEmpty(Result.Name)) return false;
            return true;
        }

        public bool HasTop() {
            return HasCheck(0);
        }
        public bool HasMiddle() {
            return HasCheck(3);
        }
        public bool HasBottom() {
            return HasCheck(6);
        }
        public String CheckRow(List<CreateDataItem> input, int row, int keyNum) {
            if (input[row].Key == ' ' & input[row + 3].Key == ' ' & input[row + 6].Key == ' '/* || input[row].Key == ' ' & input[row + 3].Key == ' ' || input[row + 3].Key == ' ' & input[row + 6].Key == ' '*/) {
                return "";
            } else {
                return Char.ToString(input[keyNum].Key);
            }
        }
        
    }
    internal class CreateDataItem {
        public string Name { get; set; }
        public bool Data { get; set; }
        public bool Ore { get; set; }
        public int DataCount { get; set; }
        public char Key { get; set; }

        public string ConbinedName() {
            return $"{Name??""}-{Data}-{Ore}-{DataCount}";
        }
    }

    internal class CreateJson {

        public void Create(CreateData data) {
            if (data == null) return;
            if (!data.IsValid()) return;

            if (data.Type == "Shaped") {
                CreateShaped(data);
            } else {
                CreateShapeless(data);
            }
        }

        private string Ingredients(CreateDataItem item, bool advanced) {
            string keytext = "";
            if (advanced) {
                if (item.Ore) {
                    keytext += $"\"type\":\"forge:ore_dict\",\"ore\":\"{item.Name}\"";
                } else if (item.Data) {
                    keytext += $"\"item\":\"{item.Name}\",\"data\":{item.DataCount}";
                } else {
                    keytext = $"\"item\":\"{item.Name}\"";
                }
            } else {
                keytext += $"\"item\":\"{item.Name}\"";
            }
            return keytext;
        }

        private void CreateShapeless(CreateData data) {
            int min = 1;
            int max = 64;
            string countKey = "";
            if (data.Count < min) {
                data.Count = min;
            } else if (data.Count > max) {
                data.Count = max;
            }
            if (data.Count >= 2) {
                countKey = ",\"count\":" + data.Count;
            }

            string ingredients = "";
            bool isFirst = true;
            foreach (CreateDataItem item in data.Data) {
                if (!string.IsNullOrEmpty(item.Name)) {
                    if (isFirst) {
                        isFirst = false;
                    } else {
                        ingredients = ingredients + ",";
                    }
                    ingredients += "{";
                    ingredients += Ingredients(item, data.IsAdvanced);
                    ingredients += "}";
                }
            }

            string textOut = "{\"type\":\"forge:ore_shapeless\",\"result\":{";
            textOut += Ingredients(data.Result, data.IsAdvanced);
            textOut += countKey + "},\"ingredients\":[" + ingredients + "]}";

            File.WriteAllText(data.Filename + ".json", textOut);
        }
        private void CreateShaped(CreateData data) {

            if(data == null) return;
            if(!data.IsValid()) return;

            char c = 'A';
            Dictionary<string, CreateDataItem> dic = new Dictionary<string, CreateDataItem>();
            foreach (CreateDataItem item in data.Data) {
                if (!string.IsNullOrEmpty(item.Name)) {
                    if (!dic.ContainsKey(item.ConbinedName())) {
                        dic.Add(item.ConbinedName(), item);
                        item.Key = c;
                        c++;
                    } else {
                        item.Key = dic[item.ConbinedName()].Key;
                    }
                } else {
                    item.Key = ' ';
                }
            }

            string keytext = "";
            bool isFirst = true;
            foreach ( CreateDataItem item in dic.Values) {
                if (isFirst) {
                    isFirst = false;
                } else {
                    keytext += ",";
                }
                keytext += $" \"{ item.Key}\":{{";
                keytext += Ingredients(item, data.IsAdvanced);
                keytext += "}";
            }

            string shapetext = "";
            if (data.HasTop()) {
                shapetext = $"{shapetext}\"{data.CheckRow(data.Data, 0 ,0)}{data.CheckRow(data.Data, 1, 1)}{data.CheckRow(data.Data, 2, 2)}\"";
                if (data.HasMiddle() || data.HasBottom()) { 
                    shapetext += ",";
                }
            }
            if (data.HasMiddle() || data.HasBottom()) {
                shapetext = $"{shapetext}\"{data.CheckRow(data.Data, 0, 3)}{data.CheckRow(data.Data, 1, 4)}{data.CheckRow(data.Data, 2, 5)}\"";
                if (data.HasBottom()) {
                    shapetext += ",";
                }
            }
            if (data.HasBottom()) {
                //shapetext = $"{shapetext}\"{data.Data[6].Key}{data.Data[7].Key}{data.Data[8].Key}\""; ;
                shapetext = $"{shapetext}\"{data.CheckRow(data.Data, 0, 6)}{data.CheckRow(data.Data, 1, 7)}{data.CheckRow(data.Data, 2, 8)}\"";
            }



            //count
            string countText = "";
            if (data.Count >= 2 & data.Count <= 64) {
                countText = ",\"count\":" + data.Count.ToString();
            }

            string output = "{\"type\":\"minecraft:crafting_shaped\",\"pattern\":[" + shapetext + "],\"key\":{" + keytext + "}";

            output += ",\"result\":{";
            output += Ingredients(data.Result, data.IsAdvanced);
            output += countText + "}}";

            File.WriteAllText(data.Filename + ".json", output);

        }
    }
}
