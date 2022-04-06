//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MCRC.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)

using namespace std;



TInterface *Interface;
//---------------------------------------------------------------------------
__fastcall TInterface::TInterface(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*void __fastcall TInterface::addItem(String itemText) {

	if(itemText != "") {
		ItemIDList -> Items -> Add(itemText);
		CraftingSlot1 -> Items -> Add(itemText);
		CraftingSlot2 -> Items -> Add(itemText);
		CraftingSlot3 -> Items -> Add(itemText);
		CraftingSlot4 -> Items -> Add(itemText);
		CraftingSlot5 -> Items -> Add(itemText);
		CraftingSlot6 -> Items -> Add(itemText);
		CraftingSlot7 -> Items -> Add(itemText);
		CraftingSlot8 -> Items -> Add(itemText);
		CraftingSlot9 -> Items -> Add(itemText);
	}
}*/
void __fastcall TInterface::ItemIDListItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{
	int index = Item -> Index;
	ItemIDList -> Items -> Delete(index);
	CraftingSlot1 -> Items -> Delete(index);
	CraftingSlot2 -> Items -> Delete(index);
	CraftingSlot3 -> Items -> Delete(index);
	CraftingSlot4 -> Items -> Delete(index);
	CraftingSlot5 -> Items -> Delete(index);
	CraftingSlot6 -> Items -> Delete(index);
	CraftingSlot7 -> Items -> Delete(index);
	CraftingSlot8 -> Items -> Delete(index);
	CraftingSlot9 -> Items -> Delete(index);
	ResultSlot -> Items -> Delete(index);
}
//---------------------------------------------------------------------------

void __fastcall TInterface::CraftingSlot1Click(TObject *Sender)
{
	CraftingSlot1 -> Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TInterface::InputItemBoxEnter(TObject *Sender)
{
	/*String itemText=InputItemBox->Text;
	if(itemText != "") {
		ItemIDList -> Items -> Add(itemText);
		CraftingSlot1 -> Items -> Add(itemText);
		CraftingSlot2 -> Items -> Add(itemText);
		CraftingSlot3 -> Items -> Add(itemText);
		CraftingSlot4 -> Items -> Add(itemText);
		CraftingSlot5 -> Items -> Add(itemText);
		CraftingSlot6 -> Items -> Add(itemText);
		CraftingSlot7 -> Items -> Add(itemText);
		CraftingSlot8 -> Items -> Add(itemText);
		CraftingSlot9 -> Items -> Add(itemText);
        ResultSlot -> Items -> Add(itemText);
	};
    InputItemBox -> Text = "";*/
}
//---------------------------------------------------------------------------


void __fastcall TInterface::ItemInputButtonClick(TObject *Sender)
{
	String itemText=InputItemBox->Text;
	if(itemText != "") {
		ItemIDList -> Items -> Add(itemText);
		CraftingSlot1 -> Items -> Add(itemText);
		CraftingSlot2 -> Items -> Add(itemText);
		CraftingSlot3 -> Items -> Add(itemText);
		CraftingSlot4 -> Items -> Add(itemText);
		CraftingSlot5 -> Items -> Add(itemText);
		CraftingSlot6 -> Items -> Add(itemText);
		CraftingSlot7 -> Items -> Add(itemText);
		CraftingSlot8 -> Items -> Add(itemText);
		CraftingSlot9 -> Items -> Add(itemText);
		ResultSlot -> Items -> Add(itemText);
	}
	InputItemBox -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::CraftingSlot2Click(TObject *Sender)
{
    CraftingSlot2 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::CraftingSlot3Click(TObject *Sender)
{
    CraftingSlot3 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::CraftingSlot4Click(TObject *Sender)
{
    CraftingSlot4 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::CraftingSlot5Click(TObject *Sender)
{
    CraftingSlot5 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::CraftingSlot6Click(TObject *Sender)
{
    CraftingSlot6 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::CraftingSlot7Click(TObject *Sender)
{
    CraftingSlot7 -> Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TInterface::CraftingSlot8Click(TObject *Sender)
{
    CraftingSlot8 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::CraftingSlot9Click(TObject *Sender)
{
    CraftingSlot9 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ResultSlotClick(TObject *Sender)
{
    ResultSlot -> Text = "";
}
//---------------------------------------------------------------------------

int __fastcall clampNum(int input, int min, int max) {
	if (input < min) {
		input = min;
	}else if (input > max) {
		input = max;
	}

	return input;
}
//---------------------------------------------------------------------------

void __fastcall createShaped(String arr[12]) {

	String shape = "";
	String key = "";
	String countKey = "";
	bool isTopRow = True;
	bool isMiddleRow = True;
	bool isBottomRow = True;

	String craftSlot1 = arr[0];
	String craftSlot2 = arr[1];
	String craftSlot3 = arr[2];
	String craftSlot4 = arr[3];
	String craftSlot5 = arr[4];
	String craftSlot6 = arr[5];
	String craftSlot7 = arr[6];
	String craftSlot8 = arr[7];
	String craftSlot9 = arr[8];
	String result = arr[9];
	String fileName = arr[10];
	String count = arr[11];

    //constructing repice shape
	if ((craftSlot1 + craftSlot2 + craftSlot3) == "") {
		isTopRow = False;
	}

	if ((craftSlot4 + craftSlot5 + craftSlot6) == "") {
		isMiddleRow = False;
	}

	if ((craftSlot7 + craftSlot8 + craftSlot9) == "") {
		isBottomRow = False;
	}

	String unqiueItems[9] {};
	String pattern[9] {};
	int numItems = 0;
	char c ='A';

	for (int i = 0; i < 9; i++) {
		if (arr[i] != "") {
			bool found = False;
			for (int ii = 0; ii <= numItems; ii++) {
				if (arr[i] == unqiueItems[ii]) {
					found = True;
					pattern[i] = char(c + ii);
					break;
				}
			}
			if (!found) {
				unqiueItems[numItems] = arr[i];
				pattern[i] = char(c + numItems);
				numItems++;
			}

		}else {
			pattern[i] = " ";
		}
	}

	bool isFirst = True;
	for (int i = 0; i < numItems; i++) {
		if (isFirst) {
			isFirst = False;
		}else {
			key = key + ",";
		}
		 key = key + "\"" + c + "\":{\"item\":\"" + unqiueItems[i] + "\"}";
		 c++;
	}

	if (isTopRow) {
		shape = shape + "\"" + pattern[0] + pattern[1] + pattern[2] + "\"";
		if (isMiddleRow || isBottomRow) {
			shape = shape + ",";
		}
	}

	if (isMiddleRow) {
		shape = shape + "\"" + pattern[3] + pattern[4] + pattern[5] + "\"";
		if (isBottomRow) {
			shape = shape + ",";
        }
	}

	if (isBottomRow) {
		shape = shape + "\"" + pattern[6] + pattern[7] + pattern[8] + "\"";
	}

	//count
	if (count >= 2 & count <= 64) {
		countKey = ",\"count\":" + count;
	}

	//constructing repice
	//"key":{"I":{"item": "ia:ingot_dark"},"S":{"item": "minecraft:stick"}}, -- key syntax
	// \"I\":{\"item\":\"ia:ingot_dark\"}}
	String TextOut = "{\"type\":\"minecraft:crafting_shaped\",\"pattern\":[" + shape + "],\"key\":{" + key + "},\"result\":{\"item\": \"" + result + "\"" + countKey + "}}";

	//writing file

  char * cstr = new char [fileName.Length()+1];
  for(int i=0; i<fileName.Length();i++){
	cstr[i] = (char)fileName.c_str()[i];
  }
  char * cstr2 = new char [TextOut.Length()+1];
  for(int i=0; i<TextOut.Length();i++){
	cstr2[i] = (char)TextOut.c_str()[i];
  }


	std::ofstream outfile;
	outfile.open(cstr);
	outfile << cstr2 << endl;
	outfile.close();
}
//---------------------------------------------------------------------------

void __fastcall createShapeless(String arr[12]) {
	int min = 1;
	int max = 64;
	String countKey = "";
	String ingredients = "";

	String craftSlot1 = arr[0];
	String craftSlot2 = arr[1];
	String craftSlot3 = arr[2];
	String craftSlot4 = arr[3];
	String craftSlot5 = arr[4];
	String craftSlot6 = arr[5];
	String craftSlot7 = arr[6];
	String craftSlot8 = arr[7];
	String craftSlot9 = arr[8];
	String result = arr[9];
	String fileName = arr[10];
	String count = arr[11];
	if (count < min) {
		count = min;
	}else if (count > max) {
		count = max;
	}
	if (count >= 2) {
		countKey = ",\"count\":" + count;
	}

	bool isFirst = True;
	for (int i = 0; i < 9; i++) {
		if (arr[i] != "") {
            if (isFirst) {
				isFirst = False;
			}else {
				ingredients = ingredients + ",";
			}
			ingredients = ingredients + "{\"item\":\"" + arr[i] + "\"}";
		}
	}

	String textOut = "{\"type\":\"forge:ore_shapeless\",\"result\":{\"item\":\"" + result + "\"" + countKey + "},\"ingredients\":[" + ingredients + "]}";

	char * cstr = new char [fileName.Length()+1];
	for(int i=0; i<fileName.Length();i++){
	cstr[i] = (char)fileName.c_str()[i];
	}
	char * cstr2 = new char [textOut.Length()+1];
	for(int i=0; i<textOut.Length();i++){
	cstr2[i] = (char)textOut.c_str()[i];
	}


	std::ofstream outfile;
	outfile.open(cstr);
	outfile << cstr2 << endl;
	outfile.close();
}
//---------------------------------------------------------------------------

void __fastcall TInterface::CreateJsonButtonClick(TObject *Sender)
{
	// extracting choices from slots
	String craftSlot1 = CraftingSlot1 -> Text;
	String craftSlot2 = CraftingSlot2 -> Text;
	String craftSlot3 = CraftingSlot3 -> Text;
	String craftSlot4 = CraftingSlot4 -> Text;
	String craftSlot5 = CraftingSlot5 -> Text;
	String craftSlot6 = CraftingSlot6 -> Text;
	String craftSlot7 = CraftingSlot7 -> Text;
	String craftSlot8 = CraftingSlot8 -> Text;
	String craftSlot9 = CraftingSlot9 -> Text;
	String result = ResultSlot -> Text;
	String fileName = FileNameEdit -> Text + ".json";
	String count = CountEdit -> Text;

	//packing data into array
	String data[12] = {
		craftSlot1,
		craftSlot2,
		craftSlot3,
		craftSlot4,
		craftSlot5,
		craftSlot6,
		craftSlot7,
		craftSlot8,
		craftSlot9,
		result,
		fileName,
		count
	};

	//creating file
	createShaped(data);
}
//---------------------------------------------------------------------------





void __fastcall TInterface::ShapelessAddButtonClick(TObject *Sender)
{
	String itemText = ShapelessItemInputEdit -> Text;
	if(itemText != "") {
		ShapelessItemIDList -> Items -> Add(itemText);
		ShapelessSlot1 -> Items -> Add(itemText);
		ShapelessSlot2 -> Items -> Add(itemText);
		ShapelessSlot3 -> Items -> Add(itemText);
		ShapelessSlot4 -> Items -> Add(itemText);
		ShapelessSlot5 -> Items -> Add(itemText);
		ShapelessSlot6 -> Items -> Add(itemText);
		ShapelessSlot7 -> Items -> Add(itemText);
		ShapelessSlot8 -> Items -> Add(itemText);
		ShapelessSlot9 -> Items -> Add(itemText);
		ShapelessResultSlot -> Items -> Add(itemText);
	}
	ShapelessItemInputEdit -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessItemIDListItemClick(TCustomListBox * const Sender,
          TListBoxItem * const Item)
{
    int index = Item -> Index;
	ShapelessItemIDList -> Items -> Delete(index);
	ShapelessSlot1 -> Items -> Delete(index);
	ShapelessSlot2 -> Items -> Delete(index);
	ShapelessSlot3 -> Items -> Delete(index);
	ShapelessSlot4 -> Items -> Delete(index);
	ShapelessSlot5 -> Items -> Delete(index);
	ShapelessSlot6 -> Items -> Delete(index);
	ShapelessSlot7 -> Items -> Delete(index);
	ShapelessSlot8 -> Items -> Delete(index);
	ShapelessSlot9 -> Items -> Delete(index);
	ShapelessResultSlot -> Items -> Delete(index);
}
//---------------------------------------------------------------------------



void __fastcall TInterface::ShapelessSlot1Click(TObject *Sender)
{
	ShapelessSlot1 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessSlot2Click(TObject *Sender)
{
	ShapelessSlot2 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessSlot3Click(TObject *Sender)
{
	ShapelessSlot3 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessSlot4Click(TObject *Sender)
{
	ShapelessSlot4 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessSlot5Click(TObject *Sender)
{
	ShapelessSlot5 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessSlot6Click(TObject *Sender)
{
	ShapelessSlot6 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessSlot7Click(TObject *Sender)
{
	ShapelessSlot7 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessSlot8Click(TObject *Sender)
{
	ShapelessSlot8 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessSlot9Click(TObject *Sender)
{
	ShapelessSlot9 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TInterface::ShapelessCreateJsonButtonClick(TObject *Sender)
{
	String craftSlot1 = ShapelessSlot1 -> Text;
	String craftSlot2 = ShapelessSlot2 -> Text;
	String craftSlot3 = ShapelessSlot3 -> Text;
	String craftSlot4 = ShapelessSlot4 -> Text;
	String craftSlot5 = ShapelessSlot5 -> Text;
	String craftSlot6 = ShapelessSlot6 -> Text;
	String craftSlot7 = ShapelessSlot7 -> Text;
	String craftSlot8 = ShapelessSlot8 -> Text;
	String craftSlot9 = ShapelessSlot9 -> Text;
	String result = ShapelessResultSlot -> Text;
	String fileName = ShapelessJsonFileName -> Text + ".json";
	String count = ShapelessCount -> Text;

	String data[12] = {
		craftSlot1,
		craftSlot2,
		craftSlot3,
		craftSlot4,
		craftSlot5,
		craftSlot6,
		craftSlot7,
		craftSlot8,
		craftSlot9,
		result,
		fileName,
		count
	};

	createShapeless(data);
}
//---------------------------------------------------------------------------

