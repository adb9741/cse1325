#include "mainwin.h"
#include <sstream>

Mainwin::Mainwin() : store{new Store{}}, filename{"untitled.elsa"}
{
	set_default_size(400, 600);
	set_title("ELSA");

	Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    	add(*vbox);

	//MENU BAR
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	//	FILE
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	//		FILE > OPEN
	Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
	menuitem_open->signal_activate().connect([this] {this->on_open_click();});
	filemenu->append(*menuitem_open);

	//		FILE > SAVE
	Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
	menuitem_save->signal_activate().connect([this] {this->on_save_click();});
	filemenu->append(*menuitem_save);

	//		FILE > SAVE AS
	Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save As", true));
	menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
	filemenu->append(*menuitem_saveas);

	//		FILE > QUIT
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
	filemenu->append(*menuitem_quit);

	//	VIEW
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_view);
	Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);

	//		VIEW > CUSTOMERS
	Gtk::MenuItem *menuitem_view_customer = Gtk::manage(new Gtk::MenuItem("_Customers", true));
	menuitem_view_customer->signal_activate().connect([this] {this->on_view_customer_click();});
	viewmenu->append(*menuitem_view_customer);

	//		VIEW > PERIPHERALS
	Gtk::MenuItem *menuitem_view_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripherals", 	true));
	menuitem_view_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
	viewmenu->append(*menuitem_view_peripheral);
	

	//		VIEW > DESKTOPS
	Gtk::MenuItem *menuitem_view_desktop = Gtk::manage(new Gtk::MenuItem("_Desktops", true));
	menuitem_view_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
	viewmenu->append(*menuitem_view_desktop);

	//		VIEW > ORDERS
	Gtk::MenuItem *menuitem_view_order = Gtk::manage(new Gtk::MenuItem("_Orders", true));
	menuitem_view_order->signal_activate().connect([this] {this->on_view_order_click();});
	viewmenu->append(*menuitem_view_order);

	//	INSERT
	Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
	menubar->append(*menuitem_insert);
	Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
	menuitem_insert->set_submenu(*insertmenu);

	//		INSERT > CUSTOMERS
	Gtk::MenuItem *menuitem_insert_customer = Gtk::manage(new Gtk::MenuItem("_Customers", 		true));
	menuitem_insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
	insertmenu->append(*menuitem_insert_customer);

	//		INSERT > PERIPHERALS
	Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripherals", 		true));
	insertmenu->append(*menuitem_insert_peripheral);
	Gtk::Menu *insertperipheralmenu = Gtk::manage(new Gtk::Menu());
	menuitem_insert_peripheral->set_submenu(*insertperipheralmenu);
	 // INSERT > PERIPHERALS > RAM
	Gtk::MenuItem *menuitem_insert_peripheral_ram = Gtk::manage(new Gtk::MenuItem("_Ram", true));
	menuitem_insert_peripheral_ram->signal_activate().connect([this] {this->on_insert_peripheral_ram_click();});
	insertperipheralmenu->append(*menuitem_insert_peripheral_ram);
	// INSERT > PERIPHERALS > OTHER
	Gtk::MenuItem *menuitem_insert_peripheral_other = Gtk::manage(new Gtk::MenuItem("_Other", true));
	menuitem_insert_peripheral_other->signal_activate().connect([this] {this->on_insert_peripheral_other_click();});
	insertperipheralmenu->append(*menuitem_insert_peripheral_other);

	//		INSERT > DESKTOPS
	Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("_Desktops", true));
	menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
	insertmenu->append(*menuitem_insert_desktop);

	//		INSERT > ORDERS
	Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Orders", true));
	menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
	insertmenu->append(*menuitem_insert_order);

	//	HELP
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	menubar->append(*menuitem_help);
	Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
	menuitem_help->set_submenu(*helpmenu);

	//		HELP > ABOUT
	Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
	menuitem_about->signal_activate().connect([this] {this->on_about_click();});
	helpmenu->append(*menuitem_about);

	//		HELP > EASTER
	Gtk::MenuItem *menuitem_easter = Gtk::manage(new Gtk::MenuItem("_Easter Egg", true));
	menuitem_easter->signal_activate().connect([this] {this->on_easter_egg_click();});
	helpmenu->append(*menuitem_easter);

	//DISPLAY WINDOW
	data = Gtk::manage(new Gtk::Label());
	data->set_hexpand(true);
	data->set_vexpand(true);
	vbox->add(*data);

	//STATUS BAR
	msg = Gtk::manage(new Gtk::Label());
	msg->set_hexpand(true);
	vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
	
	vbox->show_all();
}

Mainwin::~Mainwin(){ }

void Mainwin::on_quit_click()
{
	close();
}

void Mainwin::on_view_peripheral_click()
{
	std::ostringstream oss;
	for(int i=0; i < store->num_options(); i++)
	        oss << i << ") " << store->option(i) << "\n";
	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_view_desktop_click()
{
	std::ostringstream oss;
	for(int i=0; i < store->num_desktops(); i++){
	        oss << i << ") " << store->desktop(i) << "\n";
	}
	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_view_order_click()
{
	std::ostringstream oss;
	for(int i=0; i < store->num_orders(); i++)
	        oss << i << ") " << store->order(i) << "\n";
	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_view_customer_click()
{
	std::ostringstream oss;
	for(int i=0; i < store->num_customers(); i++)
	        oss << i << ") " << store->customer(i) << "\n\n";
	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_insert_peripheral_ram_click()
{	
	int gb = get_int("# of GB? ");
	std::string s = get_string("Name of new peripheral? ");
	double cost = get_double("Cost? ");
	if (gb) {
		Ram ram{s, cost, gb};
		store->add_option(ram);
	} 
	else {
		std::cin.clear();
		std::cerr << "#### INVALID PRICE ####\n\n";
		std::cin.ignore(32767, '\n');
	}
	on_view_peripheral_click();
	set_msg("ADDED NEW PERIPHERAL");

}

void Mainwin::on_insert_peripheral_other_click()
{
	std::string s = get_string("Name of new peripheral? ");
	double cost = get_double("Cost? ");
	
	if (cost) {
		Options option{s, cost};
		store->add_option(option);
	} 
	else {
		std::cin.clear();
		std::cerr << "#### INVALID PRICE ####\n\n";
		std::cin.ignore(32767, '\n');
	}
	on_view_peripheral_click();
	set_msg("ADDED NEW PERIPHERAL");
}

void Mainwin::on_insert_desktop_click()
{
	on_view_peripheral_click();
	int desktop = store->new_desktop();
	while(true) {
		int option = get_int("\nAdd which peripheral (-1 when done)? ");
		if(option == -1) break;
		try {
	 		store->add_option(option, desktop);
		} catch(std::exception& e) {
		std::cerr << "#### INVALID OPTION ####\n\n";
		}
	}
	on_view_desktop_click();
	set_msg("ADDED NEW DESKTOP");
}

void Mainwin::on_insert_order_click()
{
	int customer = -1;
	int order    = -1;
	int desktop  = -1;
	try {
		customer = get_int("Customer? ");
		order = store->new_order(customer);
		desktop = 0;
	} catch(std::exception& e) {
		std::cerr << "#### UNABLE TO CREATE ORDER FOR CUSTOMER " 
			<< customer << " ####\n\n"; 
		// std::cerr << store->customers.at(customer);
	}

	while(desktop >= 0) {		
		desktop = get_int("Desktop (-1 when done)? ");
		if(desktop == -1) break;
		try {
			store->add_desktop(desktop, order);
		} catch (std::exception& e) {
		std::cerr << "#### UNABLE TO ADD DESKTOP " << desktop
			<< " TO ORDER " << order << std::endl;
		desktop = 0;
		}
	}
	on_view_order_click();
	set_msg("ADDED NEW ORDER");
}

void Mainwin::on_insert_customer_click()
{
	Gtk::Dialog dialog{"Insert Customer", *this};

	Gtk::Grid grid;

	Gtk::Label labelname{"Name"};
	Gtk::Entry entryname;
	grid.attach(labelname, 0, 0, 1, 1);
	grid.attach(entryname, 1, 0, 2, 1);

	Gtk::Label labelphone{"Phone"};
	Gtk::Entry entryphone;
	grid.attach(labelphone, 0, 1, 1, 1);
	grid.attach(entryphone, 1, 1, 2, 1);

	Gtk::Label labelemail{"Email"};
	Gtk::Entry entryemail;
	grid.attach(labelemail, 0, 2, 1, 1);
	grid.attach(entryemail, 1, 2, 2, 1);

	dialog.get_content_area()->add(grid);

	dialog.add_button("Insert", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

	dialog.show_all();

	int response;

	if((response = dialog.run()) ==  Gtk::RESPONSE_OK){
		int confirm;
		while(confirm != Gtk::RESPONSE_OK){
			if(entryname.get_text().size() ==0){
				entryname.set_text("*required*");
			}
			if(entryphone.get_text().size() == 0){
				entryphone.set_text("*required*");
			}
			if(entryemail.get_text().size() == 0){
				entryemail.set_text("*required*");
			}

			Gtk::Dialog warning {"WARNING", *this};
			Gtk::Label _warning{"INVALID DATA"};
			warning.get_content_area()->pack_start(_warning, Gtk::PACK_SHRINK, 0);
			warning.add_button("Ok", Gtk::RESPONSE_OK);
			warning.show_all();
			confirm = warning.run();
			set_msg("Invalid data, try again");

		
		}

		if(entryname.get_text().size() != 0 && entryphone.get_text().size() != 0 && entryemail.get_text().size() != 0 && entryname.get_text() != "*required*" && entryphone.get_text() != "*required*" && entryemail.get_text() != "*required*"){
			std::string name = entryname.get_text();
			std::string phone = entryphone.get_text();
			std::string email = entryemail.get_text();

			Customer customer{name, phone, email};
			store->add_customer(customer);
			on_view_customer_click();
			set_msg("ADDED NEW CUSTOMER");
		}
	}

}

void Mainwin::on_about_click()
{
	Gtk::AboutDialog dialog;
	dialog.set_transient_for(*this); // Avoid the discouraging warning
	dialog.set_program_name("ELSA");
	dialog.set_version("Version 0.2");
	dialog.set_copyright("Copyright 2019-2020");
	dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
	std::vector< Glib::ustring > authors = {"Kendall B. Buchanan"};
	dialog.set_authors(authors);
	dialog.run();
}

	//UTILITY METHODS

std::string Mainwin::get_string(std::string prompt)
{
	EntryDialog edialog(*this, prompt, true);
	edialog.run();
	return edialog.get_text();
}


double Mainwin::get_double(std::string prompt)
{
	return std::stod(get_string(prompt));
}

int Mainwin::get_int(std::string prompt)
{
	return std::stoi(get_string(prompt));
}


void Mainwin::set_data(std::string s)
{
	data->set_markup(s);
}

void Mainwin::set_msg(std::string s)
{
	msg->set_markup(s);
}

void Mainwin::on_new_store_click()
{
	
}

void Mainwin::on_save_click()
{
	try 
	{
		std::ofstream ofs{filename};
		store->save(ofs);
		if(!ofs) throw std::runtime_error{"Error writing file"};
	} 
	catch(std::exception& e) 
	{
		Gtk::MessageDialog{*this, "Unable to save file: "}.run();
	}
}

void Mainwin::on_save_as_click() {
	Gtk::FileChooserDialog dialog("Please choose a file",
	  Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
	dialog.set_transient_for(*this);

	auto filter_elsa = Gtk::FileFilter::create();
	filter_elsa->set_name("ELSA files");
	filter_elsa->add_pattern("*.elsa");
	dialog.add_filter(filter_elsa);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	dialog.set_filename("untitled.elsa");

	//Add response buttons the the dialog:
	dialog.add_button("_Cancel", 0);
	dialog.add_button("_Save", 1);

	int result = dialog.run();

	if (result == 1) 
	{
		filename = dialog.get_filename();
		on_save_click();
	}
}

void Mainwin::on_open_click()
{
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	auto filter_elsa = Gtk::FileFilter::create();
	filter_elsa->set_name("ELSA files");
	filter_elsa->add_pattern("*.elsa");
	dialog.add_filter(filter_elsa);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	dialog.set_filename("untitled.elsa");

	//Add response buttons the the dialog:
	dialog.add_button("_Cancel", 0);
	dialog.add_button("_Open", 1);

	int result = dialog.run();

	if (result == 1) 
	{

		filename = dialog.get_filename();
		try 
		{
			delete store;
			std::ifstream ifs{filename};
			store = new Store{ifs};


		} 
		catch (std::exception& e) 
		{
			Gtk::MessageDialog{*this, "Unable to open file"}.run();
		}
	}
}

void Mainwin::on_easter_egg_click() {
	Customer c{"Bugs Bunny", "817-ACA-RROT", "bugs@loony.tunes"};          store->add_customer(c);
	c = Customer{"Elastigirl", "817-STR-ETCH", "helen@incredibles.movie"}; store->add_customer(c);
	c = Customer{"Tuck and Roll", "817-UFI-RED2", "circus@bugs.life"};     store->add_customer(c);
	c = Customer{"Tiana", "817-NOG-RIMM", "princess@lily.pad"};            store->add_customer(c);

	Options o{"CPU: 2.6 GHz Xeon 6126T", 2423.47};         store->add_option(o);
	o = Options{"CPU: 2.4 GHz Core i7-8565U", 388.0};      store->add_option(o);
	o = Options{"CPU: 2.2 GHz AMD Opteron", 37.71};        store->add_option(o);
	o = Options{"CPU: 300 MHz AM3351BZCEA30R ARM", 11.03}; store->add_option(o);
	o = Options{"CPU: 240 MHz ColdFire MCF5", 17.33};      store->add_option(o);

	o = Options{"2 GB RAM", 17.76};                        store->add_option(o);
	o = Options{"4 GB RAM", 22.95};                        store->add_option(o);
	o = Options{"8 GB RAM", 34.99};                        store->add_option(o);
	o = Options{"16 GB RAM", 92.99};                       store->add_option(o);
	o = Options{"32 GB RAM", 134.96};                      store->add_option(o);
	o = Options{"64 GB RAM", 319.99};                      store->add_option(o);

	o = Options{"0.5 TB SSD", 79.99};                      store->add_option(o);
	o = Options{"1 TB SSD", 109.99};                       store->add_option(o);
	o = Options{"2 TB SSD", 229.99};                       store->add_option(o);
	o = Options{"4 TB SSD", 599.99};                       store->add_option(o);

	o = Options{"1 TB PC Disk", 44.83};                    store->add_option(o);
	o = Options{"2 TB Hybrid Disk", 59.99};                store->add_option(o);
	o = Options{"4 TB Hybrid Disk", 93.98};                store->add_option(o);

	int desktop = store->new_desktop();
	store->add_option(0, desktop);
	store->add_option(9, desktop);
	store->add_option(14, desktop);

	desktop = store->new_desktop();
	store->add_option(1, desktop);
	store->add_option(7, desktop);
	store->add_option(17, desktop);

	desktop = store->new_desktop();
	store->add_option(5, desktop);
	store->add_option(7, desktop);
	store->add_option(15, desktop);
}

