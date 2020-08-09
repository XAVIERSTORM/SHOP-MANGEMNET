							// HEADER FILE USED IN PROGRAMME

	#include<iostream>
	#include<stdlib.h>
	#include<fstream>
	using namespace std ;
							// FUNCTIONS USED IN PROGRAMME
	void Addproduct();
	void Displayproduct();
	void Buy();
	void Addnewrecruit();
	void Exit();
	void updateproduct(int ,int );
	void Displaymeminfo();
	void Display();
	void status(int);

							//CLASS USED

			class shop
		{
			public:
			  int  bid;
			  char pname[25];
			  char brand[25];
			  int  price;
        		  int  status;
					}product;

			class memb
		{
			public:
          			int mid;
				char mname[25] ;
				char job[25];
	  			long phno;
					}membr;


							//file pointers for initializing the files used in the program

	FILE *librecord;

	FILE *membrrecord;

		int main()
{
				system("clear");
                        int pass;
		do{
		 cout<<"\n\t\tEnter your shop password\n\t\t";
                         cin>>pass;
		cout<<"\t-----------------------------------------------------------------------";

			  if(pass==1004)

		{
                            system("clear");
                  		int choice=0,i;
 			cout<<"\n\t\t\t\t<< <WELCOME TO> >>\n";
			    cout<<"\n\t\t\t<< ---SHOP  MANAGEMENT SYSTEM---> >>\n";

		do
			{
			cout<<"\n\t\t~~WHAT YOU WANT~~\n\t" ;
			cout<<"\n\t 1> Add A New Product\n\t 2> Display Complete Information\n\t 3> To BUY a Product  \n\t 4> Add A New Member	\n\t 5> Exit the program\n\n\t Enter your choice <1-5>:\n\t";
		cout<<"--------------------------------------------------------------------------\n\t\t";
		    cin>>choice;

			    switch (choice)
    {
			case 1:
				Addproduct();
				break;
			case 2:
				Display();
				break;
			case 3:
				Buy();
				break;
			case 4:
				Addnewrecruit();
				break;
			case 5:
				Exit();
			default:
				cout<<" <Invalid Input...>\n";
    }
			}
	while(choice!=5);
 	}
       else
        {
	cout<<"\n\t\tIncorrect Password\n";
	cout<<"\n\t\tPLEASE TRY AGAIN\n";
	}
     }while(pass!=1004);
      return (0);

}

									//FUNCTION TO ADD PRODUCT

			void Addproduct()
	{
		    		system("clear");
		    librecord = fopen("librecord.txt","a+");
		 cout<<"\n\t----------------------------------------------------------------------\n";
		    cout<<"\t\tEnter The uniqueid of The Product :(Integer) \n\t\t";
		        cin>>product.bid;
		    cout<<"\t\tEnter The Name of The Product :\n\t\t";
		        cin>>product.pname;
		    cout<<"\t\tEnter The Name of Brand :\n\t\t";
		        cin>>product.brand;
		    cout<<"\t\tEnter the price of product:(Integer)\n\t\t";
		        cin>>product.price;
		    cout<<"\t\tEnter how many Quantity\n\t\t";
			cin>>product.status;
		 fprintf(librecord,"\n%d\t%s\t%s\t%d\t%d\t",product.bid,product.pname,product.brand,product.price,product.status);
    			fclose(librecord);
    		cout<<" \t\t A New Product has been Added Successfully...\n";
	        cout<<"\t-----------------------------------------------------------------------\n";
	}


											//FUNCTION WHICH CAN ACCESS  OTHER FUNCTION

			void Display()
		{
					system("clear");
			 cout<<"\t-----------------------------------------------------------------------\n";
				int i;
				cout<<"\n\t\tYOU WANT INFORMATION FOR\n";
				cout<<"\t\tENTER YOUR CHOICE CHOICE\n";
  				cout<<"\t\t1 FOR PRODUCT DETAILS\n";
				cout<<"\t\t2 FOR EMPLOYE DETAILS\n";
			 cout<<"\t-----------------------------------------------------------------------\n\t\t";
				cin>>i;
						 switch(i)
					{
						case 1:
						Displayproduct();
						break;
						case 2:
					        Displaymeminfo();
						break;
						default:
					cout<<" <Invalid Input...>\n";
					}
		}

									//FUNCTION TO DISPLAY ALL INFORMATION

				void Displayproduct()
	{
			 system("clear");

			FILE * f;
			f = fopen("librecord.txt","a+");
		 cout<<"\t-----------------------------------------------------------------------\n";
			cout<<"\t\t INFORMATION ABOUT PRODUCT\n";
		 cout<<"\t----------------------------------------------------------------------------------------------------\n";
	              while(fscanf(f,"%d%s%s%d%d",&product.bid,product.pname,product.brand,&product.price,&product.status)!=EOF)
		{


		cout<<"\n\t PRODUCT ID "<<product.bid<<"\t\t";
		cout<<"NAME-  "<<product.pname<<"\t\t";
		cout<<"BRAND- "<<product.brand<<"\t\t";
		cout<<"PRICE- "<<product.price<<"\t\t";
		cout<<"QUANTITY- "<<product.status<<"\t\n";

		}
 		cout<<"\t-----------------------------------------------------------------------------------------------------\n";
		fclose(f);

	}

										//FUNCTION TO SHOW INFO ABOUT MEMBER

					void Displaymeminfo()
	{
					system("clear");

				cout<<"\t\t INFORMATION ABOUT MEMBERS\n\t";
		cout<<"-------------------------------------------------------------------------------------------";
				membrrecord = fopen("membrrecord.txt","a+");
		while(fscanf(membrrecord,"\n%d\t%s\t%s\t%ld\t",&membr.mid, membr.mname,membr.job,&membr.phno)!=EOF)
		{
			cout<<"\n \t userid- "<<membr.mid<<"\t\t";
			cout<<"Name- "<<membr.mname<<"\t\t";
			cout<<"Job- "<<membr.job<<"\t\t";
			cout<<"Phone number - "<<membr.phno<<"\t\n\t";
									}
		cout<<"-------------------------------------------------------------------------------------------";
			fclose(membrrecord);
	}

												//FUNCTION TO ADD A NEW STAFF

			void Addnewrecruit()
	{
			 system("clear");
				int i;
		    membrrecord = fopen("membrrecord.txt","a+");
		cout<<"\t-----------------------------------------------------------------------\n";
    		cout<<"\tEnter The userid of the Recruit(Integer) :\n\t";
			cin>>membr.mid;
    		cout<<"\tEnter The Name of the Recruit :\n\t";
			cin>>membr.mname;
		cout<<"\tEnter The Job of the Recruit :\n\t";
			cin>>membr.job;
    		cout<<"\tEnter The phone number of the Recruit:\n\t";
			long int no;
			cin>>no;
			long int temp;
			temp=no;
			int a=0;
			do{
			a=0;
			while(no>0)
			{
				no=no/10;
				a++;
			}
			//cout<<a<<"no of digit\n";
			if(a!=10)
			{
				cout<<"\tEnter a 10 digit mobile no\n";
				cin>>no;
				temp=no;
			}
			if(a==10)
			{
			//cout<<temp<<"\n";
			membr.phno=temp;
			}
			}while(a!=10);
    		fprintf(membrrecord,"\n%d\t%s\t%s\t%ld\t",membr.mid, membr.mname,membr.job,membr.phno);

   		 cout<<"\n \t Added  A New member Successfully...\n\n\tYOU ARE A VALUABLE EMPLOYEE \n\t HIRED FOR 1 YEAR \n";
		cout<<"\t-----------------------------------------------------------------------\n";
		fclose(membrrecord);
	}
									//FUNCTION TO BUY ITEMS

				void Buy()
	{
				 system("clear");

			   	 Displayproduct();
cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"\n\t\t ABOVE ARE ITEMS AVAILABLE FOR PURCHASE";
cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
				FILE *f;
    			int i,found=0;
			f = fopen("librecord.txt","a+");
		cout<<"\tEnter the id code of product to be sell\n\t";
			cin>>i;
	while(fscanf(f,"%d%s%s%d%d",&product.bid,product.pname,product.brand,&product.price,&product.status)!=EOF)
	{

			if(product.bid==i)
		{
			found=1;
			break;
					}cout<<"\na\n";
	}
			if(found==1)
		{
			fseek(f,0,SEEK_SET);
			status(i);
					}
			else
		{
		cout<<"\t\tITEM NOT AVAILABLE\n\t";
					}
 	fclose(f);

	}
											//FUNCTION TO RETURN STRUCTURE

				void status(int i)
	{
				FILE *f;
				int k,h=0;
			cout<<"\n\t\tENTER QUANTITY\n\t\t";
			cin>>k;
			f = fopen("librecord.txt","a+");
			fseek(f,0,SEEK_SET);
cout<<"\nID\n"<<i;
		while(fscanf(f,"%d%s%s%d%d",&product.bid,product.pname,product.brand,&product.price,&product.status)!=EOF)
		{
				if(product.bid==i)
			{    cout<<"\nid\n"<<product.bid;
					if(product.status>0)
				{               h=1;
						cout<<"\nps"<<product.status-k<<"\n";
						updateproduct( i,((product.status)-k));
						cout<<"\n\tYOU HAVE TO PAY rs "<<(product.price*k)<<product.status;
						cout<<"\n\tTHE PRODUCT IS SOLD";
						cout<<"product id \n"<<product.bid;
		cout<<"\n--------------------------------------------------------------------------------------\n";
			
										} break;}}
					if(h==0)
			{
					cout<<"\n\tPRODUCT IS NOT AVAILABLE RIGHT NOW";
		cout<<"\n--------------------------------------------------------------------------------------\n";
								}
														
		cout<<"\na\n";
			fclose(f);
	}
											//FUNCTION TO UPDATE PRODUCT STATUS

				void updateproduct(int i,int q)
	{
			FILE *f,*fp;
			struct shop p,n;
			f = fopen("librecord.txt","a+");
			fp=fopen("t.txt","a+");
	while(fscanf(f,"%d%s%s%d%d",&product.bid,product.pname,product.brand,&product.price,&product.status)!=EOF)
		{cout<<"upnot";
				if(product.bid!=i)
			{
cout<<"\npidd"<<product.bid<<"\n";
				fprintf(fp,"\n%d\t%s\t%s\t%d\t%d \t",product.bid,product.pname,product.brand,product.price,product.status);
							}
		}

			fseek(fp,0,SEEK_SET);
			fseek(f,0,SEEK_SET);
while(fscanf(f,"%d%s%s%d%d",&product.bid,product.pname,product.brand,&product.price,&product.status)!=EOF)

		{cout<"\no\n";
					if(product.bid==i)
			{product.status=q;
cout<<"\ndfggg"<<product.bid<<"\nst"<<product.status<<"\n";
					
					if(product.status==0)
				{
					return(0);
								}
		fprintf(fp,"\n%d\t%s\t%s\t%d\t%d\t",product.bid,product.pname,product.brand,product.price,product.status);
			}
		}

		remove("librecord.txt");
		rename("t.txt","librecord.txt");
		fclose(f);
		fclose(fp);
	}

												//FUNCTION FOR EXIT
			void Exit()
	{
			 system("clear");
 		cout<<"\t-------------------------------------------\n";
			cout<<"\t\tTHANKS FOR USING\n";
			cout<<"\t\tSHOP MANAGEMENT SYSTEM\n\n";
			cout<<"\t\tProgram developed by--\n\n\t\tAYUSH RAJ\n\t\tANIMESH TIWARI\n\t\tAVINASH KUMAR SINGH\n";
 		cout<<"\t-------------------------------------------\n";
			exit(0);
	}
