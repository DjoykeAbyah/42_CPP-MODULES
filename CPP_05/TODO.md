ex02
5) add execute to base Form
6) add executeForm to Bureaucrat



1) remove/check all todo's
2) run test ex00
3) run test ex01
4) run test ex02
5) run test ex03
6) check for hidden files


	std::cout << "**\n\n---------------- creating valid forms ----------------**" << std::endl;
	try
	{
		//creating default constructor form
		ShrubberyCreationForm form1("Kitchen");
		std::cout << form1 << std::endl;
		
		Bureaucrat boss("Boss", 150);
		std::cout << boss << std::endl;

		// //creating parametric constructor form
		// AForm* form2 = new AForm("Hallpass", 20, 20);
		// std::cout << *form2 << std::endl;
		boss.executeForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	}