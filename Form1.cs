namespace MC_Recipe_Builder
{
    public partial class MCRB : Form
    {
        public MCRB()
        {
            InitializeComponent();
        }

        private void AddItem(string name) {
            if (string.IsNullOrEmpty(name)) return;
            if (listBoxNames.Items.Contains(name)) return;
            //basic combo boxes
            comboBox1.Items.Add(name);
            comboBox2.Items.Add(name);
            comboBox3.Items.Add(name);
            comboBox4.Items.Add(name);
            comboBox5.Items.Add(name);
            comboBox6.Items.Add(name);
            comboBox7.Items.Add(name);
            comboBox8.Items.Add(name);
            comboBox9.Items.Add(name);
            resultBox.Items.Add(name);
            listBoxNames.Items.Add(name);

            //advanced combo boxes
            comboBoxAd1.Items.Add(name);
            comboBoxAd2.Items.Add(name);
            comboBoxAd3.Items.Add(name);
            comboBoxAd4.Items.Add(name);
            comboBoxAd5.Items.Add(name);
            comboBoxAd6.Items.Add(name);
            comboBoxAd7.Items.Add(name);
            comboBoxAd8.Items.Add(name);
            comboBoxAd9.Items.Add(name);

            comboBoxAdResult.Items.Add(name);
        }
        private void RemoveItem(string name) {
            //basic combo boxes
            comboBox1.Items.Remove(name);
            comboBox2.Items.Remove(name);
            comboBox3.Items.Remove(name);
            comboBox4.Items.Remove(name);
            comboBox5.Items.Remove(name);
            comboBox6.Items.Remove(name);
            comboBox7.Items.Remove(name);
            comboBox8.Items.Remove(name);
            comboBox9.Items.Remove(name);
            resultBox.Items.Remove(name);

            //advanced combo boxes
            comboBoxAd1.Items.Remove(name);
            comboBoxAd2.Items.Remove(name);
            comboBoxAd3.Items.Remove(name);
            comboBoxAd4.Items.Remove(name);
            comboBoxAd5.Items.Remove(name);
            comboBoxAd6.Items.Remove(name);
            comboBoxAd7.Items.Remove(name);
            comboBoxAd8.Items.Remove(name);
            comboBoxAd9.Items.Remove(name);

            listBoxNames.Items.Remove(name);
        }

        private void butCreateJson_Click(object sender, EventArgs e)
        {
            CreateData data = new CreateData();
            data.Filename = tbFileName.Text;
            //data.Result = resultBox.Text;
            //data.AdResult = comboBoxAdResult.Text;

            data.Type = cbShapeType.Text;

            if (comboBoxIsAdvanced.Text == "Advanced") {
                data.IsAdvanced = true;
  
                data.Data = new List<CreateDataItem> {
                    new CreateDataItem() { Name = comboBoxAd1.Text, Data = checkBoxAdData1.Checked, Ore=checkBoxAdOre1.Checked, DataCount = Convert.ToInt32(numericUpDown1.Value) },
                    new CreateDataItem() { Name = comboBoxAd2.Text, Data = checkBoxAdData2.Checked, Ore=checkBoxAdOre2.Checked, DataCount = Convert.ToInt32(numericUpDown2.Value) },
                    new CreateDataItem() { Name = comboBoxAd3.Text, Data = checkBoxAdData3.Checked, Ore=checkBoxAdOre3.Checked, DataCount = Convert.ToInt32(numericUpDown3.Value) },
                    new CreateDataItem() { Name = comboBoxAd4.Text, Data = checkBoxAdData4.Checked, Ore=checkBoxAdOre4.Checked, DataCount = Convert.ToInt32(numericUpDown4.Value) },
                    new CreateDataItem() { Name = comboBoxAd5.Text, Data = checkBoxAdData5.Checked, Ore=checkBoxAdOre5.Checked, DataCount = Convert.ToInt32(numericUpDown5.Value) },
                    new CreateDataItem() { Name = comboBoxAd6.Text, Data = checkBoxAdData6.Checked, Ore=checkBoxAdOre6.Checked, DataCount = Convert.ToInt32(numericUpDown6.Value) },
                    new CreateDataItem() { Name = comboBoxAd7.Text, Data = checkBoxAdData7.Checked, Ore=checkBoxAdOre7.Checked, DataCount = Convert.ToInt32(numericUpDown7.Value) },
                    new CreateDataItem() { Name = comboBoxAd8.Text, Data = checkBoxAdData8.Checked, Ore=checkBoxAdOre8.Checked, DataCount = Convert.ToInt32(numericUpDown8.Value) },
                    new CreateDataItem() { Name = comboBoxAd9.Text, Data = checkBoxAdData9.Checked, Ore=checkBoxAdOre9.Checked, DataCount = Convert.ToInt32(numericUpDown9.Value) }
                };
                data.Count = Convert.ToInt32(AdCount.Value);
                data.Result = new CreateDataItem { Name = comboBoxAdResult.Text, Data = checkBoxAdDataResult.Checked, Ore = checkBoxAdOreResult.Checked, DataCount = Convert.ToInt32(numericUpDownResult.Value) };
            } else {
                data.IsAdvanced = false;

                data.Data = new List<CreateDataItem> {
                    new CreateDataItem() { Name = comboBox1.Text},
                    new CreateDataItem() { Name = comboBox2.Text},
                    new CreateDataItem() { Name = comboBox3.Text},
                    new CreateDataItem() { Name = comboBox4.Text},
                    new CreateDataItem() { Name = comboBox5.Text},
                    new CreateDataItem() { Name = comboBox6.Text},
                    new CreateDataItem() { Name = comboBox7.Text},
                    new CreateDataItem() { Name = comboBox8.Text},
                    new CreateDataItem() { Name = comboBox9.Text}
                };
            data.Count = Convert.ToInt32(numCount.Value);
                data.Result = new CreateDataItem { Name = resultBox.Text};
            }

            //data.Data = new List<string> { comboBox1.Text, comboBox2.Text, comboBox3.Text, comboBox4.Text, comboBox5.Text, comboBox6.Text, comboBox7.Text, comboBox8.Text, comboBox9.Text };
            //data.AdvancedData = new List<string> { comboBoxAd1.Text, comboBoxAd2.Text, comboBoxAd3.Text, comboBoxAd4.Text, comboBoxAd5.Text, comboBoxAd6.Text, comboBoxAd7.Text, comboBoxAd8.Text, comboBoxAd9.Text};
            //data.CheckData = new List<bool> {
            //    checkBoxAdData1.Checked, checkBoxAdOre1.Checked,
            //    checkBoxAdData2.Checked, checkBoxAdOre2.Checked,
            //    checkBoxAdData3.Checked, checkBoxAdOre3.Checked,
            //    checkBoxAdData4.Checked, checkBoxAdOre4.Checked,
            //    checkBoxAdData5.Checked, checkBoxAdOre5.Checked,
            //    checkBoxAdData6.Checked, checkBoxAdOre6.Checked,
            //    checkBoxAdData7.Checked, checkBoxAdOre7.Checked,
            //    checkBoxAdData8.Checked, checkBoxAdOre8.Checked,
            //    checkBoxAdData9.Checked, checkBoxAdOre9.Checked,
            //};

            CreateJson c=new CreateJson();
            c.Create(data);
            
        }

        private void butAdd_Click(object sender, EventArgs e) {
            AddItem(textBoxName.Text);
            textBoxName.Text = "";
        }

        private void butRemove_Click(object sender, EventArgs e) {
            if (listBoxNames.SelectedIndex == -1) return;
            RemoveItem(listBoxNames.SelectedItem.ToString());   
        }

        private void label1_Click(object sender, EventArgs e) {

        }

        private void textBox1_TextChanged(object sender, EventArgs e) {

        }

        private void butClearList_Click(object sender, EventArgs e) {
            listBoxNames.Items.Clear();
            //basic combo boxes
            comboBox1.Items.Clear();
            comboBox2.Items.Clear();
            comboBox3.Items.Clear();
            comboBox4.Items.Clear();
            comboBox5.Items.Clear();
            comboBox6.Items.Clear();
            comboBox7.Items.Clear();
            comboBox8.Items.Clear();
            comboBox9.Items.Clear();
            resultBox.Items.Clear();

            //advanced combo boxes
            comboBoxAd1.Items.Clear();
            comboBoxAd2.Items.Clear();
            comboBoxAd3.Items.Clear();
            comboBoxAd4.Items.Clear();
            comboBoxAd5.Items.Clear();
            comboBoxAd6.Items.Clear();
            comboBoxAd7.Items.Clear();
            comboBoxAd8.Items.Clear();
            comboBoxAd9.Items.Clear();

            butClearSlots_Click(null, null);
        }

        private void butClearSlots_Click(object sender, EventArgs e) {
            //basic combo boxes
            comboBox1.Text = "";
            comboBox2.Text = "";
            comboBox3.Text = "";
            comboBox4.Text = "";
            comboBox5.Text = "";
            comboBox6.Text = "";
            comboBox7.Text = "";
            comboBox8.Text = "";
            comboBox9.Text = "";
            resultBox.Text = "";

            //advanced combo boxes
            comboBoxAd1.Text = "";
            comboBoxAd2.Text = "";
            comboBoxAd3.Text = "";
            comboBoxAd4.Text = "";
            comboBoxAd5.Text = "";
            comboBoxAd6.Text = "";
            comboBoxAd7.Text = "";
            comboBoxAd8.Text = "";
            comboBoxAd9.Text = "";
            comboBoxAdResult.Text = "";

            //reset counters
            numCount.Value = 1;
            AdCount.Value = 1;
            numericUpDown1.Value = 0;
            numericUpDown2.Value = 0;
            numericUpDown3.Value = 0;
            numericUpDown4.Value = 0;
            numericUpDown5.Value = 0;
            numericUpDown6.Value = 0;
            numericUpDown7.Value = 0;
            numericUpDown8.Value = 0;
            numericUpDown9.Value = 0;
            numericUpDownResult.Value = 0;
            AdCount.Value = 1;

            //checks
            checkBoxAdData1.Checked = false;
            checkBoxAdData2.Checked = false;
            checkBoxAdData3.Checked = false;
            checkBoxAdData4.Checked = false;
            checkBoxAdData5.Checked = false;
            checkBoxAdData6.Checked = false;
            checkBoxAdData7.Checked = false;
            checkBoxAdData8.Checked = false;
            checkBoxAdData9.Checked = false;
            checkBoxAdDataResult.Checked = false;

            checkBoxAdOre1.Checked = false;
            checkBoxAdOre2.Checked = false;
            checkBoxAdOre3.Checked = false;
            checkBoxAdOre4.Checked = false;
            checkBoxAdOre5.Checked = false;
            checkBoxAdOre6.Checked = false;
            checkBoxAdOre7.Checked = false;
            checkBoxAdOre8.Checked = false;
            checkBoxAdOre9.Checked = false;
            checkBoxAdOreResult.Checked = false;
        }

        private void ShapeGroup_Enter(object sender, EventArgs e) {

        }

        private void MCRB_Load(object sender, EventArgs e) {

        }

        private void tabPage1_Click(object sender, EventArgs e) {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e) {

        }

        private void label2_Click(object sender, EventArgs e) {

        }

        private void label3_Click(object sender, EventArgs e) {

        }

        private void comboBox4_SelectedIndexChanged(object sender, EventArgs e) {

        }

        private void comboBox6_SelectedIndexChanged(object sender, EventArgs e) {

        }

        private void numCount_ValueChanged(object sender, EventArgs e) {

        }

        private void comboBox8_SelectedIndexChanged(object sender, EventArgs e) {

        }

        private void resultBox_SelectedIndexChanged(object sender, EventArgs e) {

        }

        private void comboBox7_SelectedIndexChanged(object sender, EventArgs e) {

        }

        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e) {

        }

        private void comboBox5_SelectedIndexChanged(object sender, EventArgs e) {

        }

        private void comboBox9_SelectedIndexChanged(object sender, EventArgs e) {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e) {

        }
    }
}