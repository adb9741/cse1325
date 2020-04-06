#include "mainwin.h"
#include <sstream>

Mainwin::Mainwin() : store{new Store{}}
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

	//		FILE > QUIT
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
	filemenu->append(*menuitem_quit);

	//	HELP
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	menubar->append(*menuitem_help);
	Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
	menuitem_help->set_submenu(*helpmenu);

	//		HELP > ABOUT
	Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
	menuitem_about->signal_activate().connect([this] {this->on_about_click();});
	helpmenu->append(*menuitem_about);

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
	menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
	insertmenu->append(*menuitem_insert_peripheral);

	//		INSERT > DESKTOPS
	Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("_Desktops", true));
	menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
	insertmenu->append(*menuitem_insert_desktop);

	//		INSERT > ORDERS
	Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Orders", true));
	menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
	insertmenu->append(*menuitem_insert_order);

	//DISPLAY WINDOW
	data = Gtk::manage(new Gtk::Label());
	data->set_hexpand(true);
	data->set_vexpand(true);
	vbox->add(*data);

	//STATUS BAR
	msg = Gtk::manage(new Gtk::Label());
	msg->set_hexpand(true);
	msg->override_background_color(Gdk::RGBA{"gray"});
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
	for(int i=0; i < store->num_desktops(); i++)
	        oss << i << ") " << store->desktop(i) << "\n";
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

void Mainwin::on_insert_peripheral_click()
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
}

void Mainwin::on_insert_desktop_click()
{
	int option = -1;
	int customer = -1;
	int desktop = store->new_desktop();
	while(true) {
		/*std::cout << store->desktop(desktop) << "\n\n";
		for(int i=0; i<store->num_options(); i++) 
			std::cout << i << ") " << store->option(i) << '\n';*/
		on_view_peripheral_click();
		if(store->num_options() != 0){
			option = get_int("\nAdd which peripheral (-1 when done)? ");
			if(option == -1) break;
			try {
		 		store->add_option(option, desktop);
			} catch(std::exception& e) {
			std::cerr << "#### INVALID OPTION ####\n\n";
			}
		}
		else
			on_insert_peripheral_click();
	}
	bool loop = true;
	while(loop == true) {
		if(store->num_customers() != 0){
			on_view_customer_click();
			customer = get_int("\nAdd to which customer (-1 when done)? ");
			if(customer == -1) break;
			else{
				try {
			 		store->add_option(option, desktop);
				} catch(std::exception& e) {
				std::cerr << "#### INVALID OPTION ####\n\n";
				}
			}
		}
		else{
			bool yesno = true;
			while(yesno == true){
				std::string answer = get_string("Would you like to add this DESKTOP to a new customer (Y/N)? ");
				if(answer == "Y" || answer == "y")
					on_insert_customer_click();
				if(answer == "N" || answer == "n") 
					yesno = false;
			}
			loop = false;
		}
	}
	on_view_desktop_click();
}

void Mainwin::on_insert_order_click()
{
	int customer = -1;
	int order    = -1;
	int desktop  = -1;

	bool loop = true;
	while(loop == true) {
		if(store->num_customers() != 0){
			on_view_customer_click();
			if(customer == -1) break;
			else{
				try {
					customer = get_int("\nAdd to which customer (-1 when done)? ");
					order = store->new_order(customer);
					desktop = 0;
				} catch(std::exception& e) {
					std::cerr << "#### UNABLE TO CREATE ORDER FOR CUSTOMER " 
						<< customer << " ####\n\n"; 
				}
				if(store->num_desktops() != 0){
					while(desktop >= 0) {
						bool yesno = true;
						while(yesno == true){
							std::string answer = get_string("Would you like to add a desktop to this 									order (Y/N)? ");
							if(answer == "Y" || answer == "y"){
								desktop = get_int("Desktop (-1 when done)? ");
								if(desktop == -1) break;
								try {
									store->add_desktop(desktop, order);
								} catch (std::exception& e) {
								std::cerr << "#### UNABLE TO ADD DESKTOP " << desktop
									<< " TO ORDER " << order << std::endl;
								desktop = 0;
							}
							if(answer == "N" || answer == "n") 
								yesno = false;
							}
						}
					}
				}
				else{
					bool yesno = true;
					while(yesno == true){
						std::string answer = get_string("Would you like to create a DESKTOP for this 									order (Y/N)? ");
						if(answer == "Y" || answer == "y"){
							on_insert_desktop_click();
						}
						if(answer == "N" || answer == "n") 
							yesno = false;
					}
				}
			}
		}
		else{
			bool yesno = true;
			while(yesno == true){
				std::string answer = get_string("Would you like to add this ORDER to a new customer (Y/N)? ");
				if(answer == "Y" || answer == "y")
					on_insert_customer_click();
				if(answer == "N" || answer == "n") 
					yesno = false;
			}
			loop = false;
		}
	}
	on_view_order_click();
}

void Mainwin::on_insert_customer_click()
{
	std::string name = get_string("Customer name? ");
	if(name.size()) {
		std::string phone = get_string("Customer phone (xxx-xxx-xxxx)? ");
		std::string email = get_string("Customer email (xxx@domain.com)? ");
		Customer customer{name, phone, email};
		store->add_customer(customer);
	}

	bool yesno = true;
	while(yesno == true){
		std::string answer = get_string("Would you like to add a new order to this customer? (Y/N)? ");
		if(answer == "Y" || answer == "y")
			on_insert_order_click();
		if(answer == "N" || answer == "n") 
			yesno = false;
	}
	on_view_customer_click();
}

void Mainwin::on_about_click()
{
	
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
	data->set_text(s);
}

void Mainwin::set_msg(std::string s)
{
	msg->set_text(s);
}
