#include "mainwin.h"
#include <iostream> 

Mainwin::Mainwin() : store{new Store{}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("ELSA");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    //
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);


    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

	//VIEW
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);
	
	//Customer
	Gtk::MenuItem *menuitem_view_customer = Gtk::manage(new Gtk::MenuItem("Customer", true));
    menuitem_view_customer->signal_activate().connect([this] {this->on_view_customer_click();});
    viewmenu->append(*menuitem_view_customer);

	//Peripheral
	Gtk::MenuItem *menuitem_view_peripheral = Gtk::manage(new Gtk::MenuItem("Peripheral", true));
    menuitem_view_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_view_peripheral);

	//Desktop
	Gtk::MenuItem *menuitem_view_desktop = Gtk::manage(new Gtk::MenuItem("Desktop", true));
    menuitem_view_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
    viewmenu->append(*menuitem_view_desktop);

	//Order
	Gtk::MenuItem *menuitem_view_order = Gtk::manage(new Gtk::MenuItem("Order", true));
    menuitem_view_order->signal_activate().connect([this] {this->on_view_order_click();});
    viewmenu->append(*menuitem_view_order);

	//Insert
	Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

	//Customer
	Gtk::MenuItem *menuitem_insert_customer = Gtk::manage(new Gtk::MenuItem("Customer", true));
    menuitem_insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
    insertmenu->append(*menuitem_insert_customer);

	//Peripheral
	Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("Peripheral", true));
    menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
    insertmenu->append(*menuitem_insert_peripheral);

	//Desktop
	Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("Desktop", true));
    menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
    insertmenu->append(*menuitem_insert_desktop);

	//Order
	Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("Order", true));
    menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
    insertmenu->append(*menuitem_insert_order);

	
    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);


	data = Gtk::manage(new Gtk::Label());
	data->set_hexpand(true);
	data->set_vexpand(true);
	vbox->add(*data);


	msg = Gtk::manage(new Gtk::Label());
	msg->set_hexpand(true);
	msg->override_background_color(Gdk::RGBA{"gray"});
	vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);


    // Make the box and everything in it visible
    vbox->show_all();

    
}

Mainwin::~Mainwin() { }


void Mainwin::on_quit_click(){

	close();
}

void Mainwin::on_view_peripheral_click(){
	std::ostringstream oss;
	for(int i = 0; i < store->num_options(); i++){
		oss << i << ") " << store->option(i) << "\n";
	}

	set_data(oss.str());
	set_msg("");
}
	
void Mainwin::on_view_desktop_click(){

	std::ostringstream oss;
	for(int i = 0; i < store->num_desktops(); i++){
		oss << i << ") " << store->desktop(i) << "\n";
	}
	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_view_order_click(){

	std::ostringstream oss;
	for(int i = 0 ; i< store->num_orders(); i ++){
		oss << i << ") " << store->order(i) << "\n";
	}

	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_view_customer_click(){
	
	std::ostringstream oss;
	for(int i = 0; i < store->num_customers(); i++){
		oss << i << ") " << store->customer(i) << "\n";
	}

	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_insert_peripheral_click(){
	std::string str = get_string("Name of peripheral?");
	double cost = get_double("Cost?");

	if(cost){
		Options option{str, cost};
		store->add_option(option);
	}
	else{
		std::cin.clear();
		std::cerr << "###INVALID PRICE ### \n\n";
		std::cin.ignore(32767, '\n');
	}

	set_msg("Peripheral successful.");
	on_view_peripheral_click();
}

void Mainwin::on_insert_desktop_click(){

	int deskt = store->new_desktop();
	int check = 1;
	while(check == 1){
		std::cout << store->desktop(deskt) << "\n";
		for(int i = 0; i <store->num_options(); i++){
			std::cout << i << ") " << store->option(i) << '\n';
		}

		int option = get_int("\nAdd which peripheral (-1 when done)");
		if(option == -1){
			break;
		}
		try{
			store->add_option(option, deskt);

		} catch(std::exception& e){
			std::cerr << "INVALID OPTION \n \n";
		}
	}
	set_msg("Desktop successful.");
	on_view_desktop_click();
}

void Mainwin::on_insert_order_click(){
	int customer = -1;
	int order = -1;
	int desktop = -1;
	try{
			for(int i = 0; i < store->num_customers(); i++){
				std::cout << i << ") " << store->customer(i) << '\n';
			}
			customer = get_int("Customer? " );
			order = store->new_order(customer);
			std::cout << "Order " << order << " created for customer " << customer << std::endl;
			desktop = 0;
	} catch(std::exception& e){
		std::cerr << "### UNABLE TO CREATE ORDER FOR CUSTOMER " << customer << " ###\n" << std::endl;

	}

	while(desktop >= 0){
		for(int i = 0; i < store->num_desktops(); i++){
			std::cout << i << ") " << store->desktop(i) << '\n';
		}
		desktop = get_int("Desktop (-1 when done)? ");
		if(desktop ==-1){
			break;
		}
		try{
				store->add_desktop(desktop, order);
		} catch (std::exception& e){
			std::cerr << "### UNABLE TO ADD DESKTOP " << desktop << "TO ORDER " << order << std::endl;
		desktop = 0;
		}
	}
	set_msg("Order successful.");
	on_view_order_click();
}

void Mainwin::on_insert_customer_click(){

	std::string name = get_string("Customer name?");
	if(name.size()){
		std::string phone = get_string("Customer phone (xxx-xxx-xxxx)");
		std::string email = get_string("Customer email (xxx@domain.com)?");
		Customer customer{name, phone, email};
		store->add_customer(customer);
	}

	set_msg("Customer successful.");
	on_view_customer_click();
}

void Mainwin::on_about_click(){
	Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("ELSA");
    auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1");
    dialog.set_copyright("Copyright 2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Ashlei Burrola"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Ashlei Burrola (P.S. I am not a logo designer)"};
    dialog.set_artists(artists);
    dialog.run();
	}

std::string Mainwin::get_string(std::string prompt){
	EntryDialog edialog(*this, prompt, true);
	edialog.run();
	return edialog.get_text();
}

double Mainwin::get_double(std::string prompt){
	return std::stod(get_string(prompt));
}

int Mainwin::get_int(std::string prompt){
	return std::stoi(get_string(prompt));
}

void Mainwin::set_data(std::string s){
	data->set_text(s);
}

void Mainwin::set_msg(std::string s){
	msg->set_text(s);
}




// void Mainwin::on_rules_click() {
//     Glib::ustring s = R"(
// <span size='24000' weight='bold'>The Rules of Nim</span>
// <span size='large'>Copyright 2017-2020 by George F. Rice - CC BY 4.0</span>

// The two players alternate taking 1 to 3 sticks from the pile. The goal is to force your opponent to take the last stick (called misère rules).

// If the computer button is up, it's a two player game. If down, the computer is always Player 2.)";
//     Gtk::MessageDialog{*this, s, true}.run(); // 'true' as 3rd parameter enables Pango markup
// }






