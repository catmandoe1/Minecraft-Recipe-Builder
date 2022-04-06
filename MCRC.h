//---------------------------------------------------------------------------

#ifndef MCRCH
#define MCRCH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ExtCtrls.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Menus.hpp>
//---------------------------------------------------------------------------
class TInterface : public TForm
{
__published:	// IDE-managed Components
	TPopupBox *CraftingSlot1;
	TListBox *ItemIDList;
	TPopupBox *CraftingSlot2;
	TPopupBox *CraftingSlot3;
	TPopupBox *CraftingSlot4;
	TPopupBox *CraftingSlot5;
	TPopupBox *CraftingSlot6;
	TPopupBox *CraftingSlot7;
	TPopupBox *CraftingSlot8;
	TPopupBox *CraftingSlot9;
	TEdit *InputItemBox;
	TButton *ItemInputButton;
	TLabel *InputLabel;
	TButton *CreateJsonButton;
	TLabel *CraftingGridText;
	TPopupBox *ResultSlot;
	TLabel *ResultLabel;
	TEdit *FileNameEdit;
	TLabel *JsonFileNameLabel;
	TLabel *Label1;
	TEdit *CountEdit;
	TLabel *CountLabel;
	TLabel *ShapedTitle;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TListBox *ShapelessItemIDList;
	TEdit *ShapelessItemInputEdit;
	TButton *ShapelessAddButton;
	TPopupBox *ShapelessSlot1;
	TLabel *ShapelessTitle;
	TLabel *ShapelessSlotEX;
	TPopupBox *ShapelessSlot2;
	TPopupBox *ShapelessSlot3;
	TPopupBox *ShapelessSlot4;
	TPopupBox *ShapelessSlot5;
	TPopupBox *ShapelessSlot6;
	TPopupBox *ShapelessSlot7;
	TPopupBox *ShapelessSlot8;
	TPopupBox *ShapelessSlot9;
	TPopupBox *ShapelessResultSlot;
	TLabel *Label2;
	TEdit *ShapelessCount;
	TLabel *Label3;
	TButton *ShapelessCreateJsonButton;
	TPanel *Panel7;
	TPanel *Panel8;
	TPanel *Panel9;
	TPanel *Panel10;
	TEdit *ShapelessJsonFileName;
	void __fastcall ItemIDListItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall CraftingSlot1Click(TObject *Sender);
	void __fastcall InputItemBoxEnter(TObject *Sender);
	void __fastcall ItemInputButtonClick(TObject *Sender);
	void __fastcall CraftingSlot2Click(TObject *Sender);
	void __fastcall CraftingSlot3Click(TObject *Sender);
	void __fastcall CraftingSlot4Click(TObject *Sender);
	void __fastcall CraftingSlot5Click(TObject *Sender);
	void __fastcall CraftingSlot7Click(TObject *Sender);
	void __fastcall CraftingSlot8Click(TObject *Sender);
	void __fastcall CraftingSlot9Click(TObject *Sender);
	void __fastcall CraftingSlot6Click(TObject *Sender);
	void __fastcall ResultSlotClick(TObject *Sender);
	void __fastcall CreateJsonButtonClick(TObject *Sender);
	void __fastcall ShapelessAddButtonClick(TObject *Sender);
	void __fastcall ShapelessItemIDListItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall ShapelessSlot1Click(TObject *Sender);
	void __fastcall ShapelessSlot2Click(TObject *Sender);
	void __fastcall ShapelessSlot3Click(TObject *Sender);
	void __fastcall ShapelessSlot4Click(TObject *Sender);
	void __fastcall ShapelessSlot5Click(TObject *Sender);
	void __fastcall ShapelessSlot6Click(TObject *Sender);
	void __fastcall ShapelessSlot7Click(TObject *Sender);
	void __fastcall ShapelessSlot8Click(TObject *Sender);
	void __fastcall ShapelessSlot9Click(TObject *Sender);
	void __fastcall ShapelessCreateJsonButtonClick(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TInterface(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInterface *Interface;
//---------------------------------------------------------------------------
#endif
