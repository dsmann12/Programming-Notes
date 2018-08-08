#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <Fl_Button.H>
#include <Fl_Return_Button>
#include <Fl_Text_Editor>


using namespace std;
//Text editor
//Provide menubar/menus for all functions
//Edit single text file, possibly with multiple view
//Load from a file
//Save to a file
//Cut/copy/pase functions
//Search and replace functions
//Keep track of when file has been changed

//Begin with design of GUI.

//Basic window:
class EditorWindow : public Fl_Double_Window {
	public:
		EditorWindow(int w, int h, const char *t);
		~EditorWindow();
	
		Fl_Window *replace_dlg;
		Fl_Input *replace_find;
		Fl_Input *replace_with;
		Fl_Button *replace_all;
		Fl_Return_Button *replace_next;
		Fl_Button *replace_cancel;
		
		Fl_Text_Editor *editor;
		char search[256];
};

int changed = 0;
char filename [256] = "";
Fl_Text_Buffer *textbuf;

//textbuf vis text editor buffer for window class 

//create menu bar
//Fl_Menu_Item structure used to define menus and items in a menu bar
Fl_Menu_Item menuitems[] = {
	{ "&File", 0, 0, 0, FL_SUBMENU },
		{ "&New File", 0, (Fl_Callback *)new_cb },
		{ "&Open File...", FL_COMMAND + 'o', (Fl_Callback *)open_cb },
		{ "&Insert File...", FL_COMMAND + 'i', (Fl_Calback *)insert_cb, 0, 
		FL_MENU_DIVIDER },
		{ "&Save File", FL_COMMAND + 's', (Fl_Callback *)save_cb },
		{ "Save File &As...", FL_COMMAND + FL_SHIFT + 's', (Fl_Callback *)saveas_cb,
		0, FL_MENU_DIVIDER },
		{ "New &View", FL_ALT + 'v', (Fl_Callback *)view_cb, 0},
		{ "&Close View", FL_COMMAND + 'w', (Fl_Callback *)close_cb, 0, 
		FL_MENU_DIVIDER },
		{ "E&xit", FL_COMMAND + 'q', (Fl_Callback *)quit_cb, 0},
		{ 0 },
	{ "&Edit", 0, 0, 0, FL_SUBMENU }.
		{ "&Undo", FL_COMMAND + 'z', (Fl_Callback *)undo_cb, 0, FL_MENU_DIVIDER },
		{ "Cu&t", FL_COMMAND + 'x', (Fl_Callback *)cut_cb },
		{ "&Copy", FL_COMMAND + 'c', (Fl_Callback *)copy_cb },
		{ "&Paste", FL_COMMAND + 'v', (Fl_Callback *)paste_cb },
		{ "&Delete", 0, (Fl_Callback *)delete_cb },
		{ 0 },
	{ "&Search", 0, 0, 0, FL_SUBMENU },
		{ "&Find...", FL_COMMAND + 'f', (Fl_Callback *)find_cb },
		{ "F&ind Again", FL_COMMAND + 'g', find2_cb },
		{ "&Replace...", FL_COMMAND + 'r', replace_cb },
		{ "Re&place Again", FL_COMMAND + 't', replace2_cb },
		{ 0 }
	{ 0 }
};

//Once menus defined, can create menu bar widget and assign menus to it:
Fl_Menu_Bar *m = new Fl_Menu_Bar(0, 0, 640, 30);
m->copy(menuitems);

//define callback functions later

//use Fl_Text_Editor widget to edit text: simple


}
