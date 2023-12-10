#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
class casino{
	public:
		int size,guess[10],choice, wheel,size1;
		double amount[10],bettingamount[10];
		bool guess1;
		string name[10];
		
		void random(){
			srand(time(0));
			wheel=rand()%37;
		}
		void rules(){
			system("cls");
			cout << "\n===============================================================================================\n";
			cout << "\t\t\tGame Rules";
			cout << "\n===============================================================================================";
			cout << "\n1. You Can Choose Number Between 0 To 36";
			cout << "\n2. Winning Amount Will Be Some Times More Then Betting Amount ";
			cout << "\n3. Loose Amount Will Be Betting Amount";
			cout << "\n===============================================================================================\n";
		}	
		void input(){
			for(int i=0;i<size;i++){
				rules();
				cout<<"\nEnter The Player"<<i+1<<" Name: ";
				cin.ignore();
				getline(cin,name[i]);
				
				do{
					cout<<"\nEnter The Deposit Your Amount(Min 5000$): $";
					cin>>amount[i];
					
					if(amount[i]<5000){
						cout<<"\nPlease Deposit Minmum $5000 Or More...";
					}else{ break; }	
				}while(1);
				
			}
			amountdisplay();
		}
		void game(){
			do{
			for(int i=0;i<size;i++){
				rules();
				random();
				do { 
					cout << "\nWelcome " << name[i] << " \nThis Is Casino The Number Guessing Game. " << "\n\nLet Us Play The Game.";
					cout<<"\nYour Current Amount: "<<amount[i];
					cout << "\nEnter Your Betting Amount: $";
					cin >> bettingamount[i];
					
					if (bettingamount[i] > amount[i]||bettingamount[i] < 0){
					cout << "You Can Not Bet More Than Current Amount Or Less Than 0...\n";
					}else{
					break;
					}
				} while (1);
				Menu();
				
				if(guess1==1){
					cout << "\nHurray You Won ";
					if(choice==1){
						cout<<"\nYour Wining Amount:"<<bettingamount[i]*35<<"\n You Got 35 Times Of Your Bitting Amount.";
						amount[i] += bettingamount[i]*35;
					}else if(choice==2 || choice == 3){
						cout<<"\nYour Wining Amount:"<<bettingamount[i]*17<<"\n You Got 17 Times Of Your Bitting Amount.";
						amount[i] += bettingamount[i]*17;
					}else if(choice == 4){
						cout<<"\nYour Wining Amount:"<<bettingamount[i]*11<<"\n You Got 11 Times Of Your Bitting Amount.";
						amount[i] += bettingamount[i]*11;
					}else if(choice == 5 || choice == 6){
						cout<<"\nYour Wining Amount:"<<bettingamount[i]*8<<"\n You Got 8 Times Of Your Bitting Amount.";
						amount[i] += bettingamount[i]*8;
					}else if(choice == 7){
						cout<<"\nYour Wining Amount:"<<bettingamount[i]*5<<"\n You Got 5 Times Of Your Bitting Amount.";
						amount[i] += bettingamount[i]*5;
					}else if(choice == 8||choice == 9||choice==10||choice==11||choice==12||choice==13){
						cout<<"\nYour Wining Amount:"<<bettingamount[i]*2<<"\n You Got 2 Times Of Your Bitting Amount.";
						amount[i] += bettingamount[i]*2;
					}else if(choice == 14||choice==15||choice==16||choice==17){
						cout<<"\nYour Wining Amount:"<<bettingamount[i]*1<<"\n You Got 1 Time Of Your Bitting Amount.";
						amount[i] += bettingamount[i]*1;
					}
				}else{
					cout << "\nSorry You Lose. \nYour Losing Amount:" <<bettingamount[i];
					amount[i] -= bettingamount[i];
				}
				do{
					int c;
					cout<<"\nEnter 1 For Next Player: ";
					cin>>c;
					if(c==1){
					break;
					}
				}while(1);
				if(amount[i]==0){
						return;
				}
			}
			int c;
			cout<<"\nEnter 1 For Next Chance or 0 For Exit: ";
			cin>>c;
			if(c==1){
			continue;
			}else if(c==0){
				break;
			}
		}while(1);
		}
		void amountdisplay(){
			for(int i=0;i<size;i++){
			   cout<<"\n\n"<<i+1<<".Player: "<<name[i];
			   cout<<"\n Current Amount: "<<amount[i];
			}
		}
		void DisplayRoulette()
    	{
        int a[12][3]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
        cout<<"Roulette Table:"<<endl;
        cout<<"   "<<"0"<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<a[i][j]<<"  ";
            }
            cout<<endl;
        }
        for(int i=3;i<12;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    	}
	    int *StraightUp()
	    {
	        static int a[1];
	        DisplayRoulette();
	        size1 = 1;
	        do{
	        	cout<<"Enter any number between 0 and 36:";
	        	cin>>a[0];
	        	if(a[0]<0||a[0]>36){
	        		cout<<"Please Enter A Number Between 0 To 36.....\n";
	        	}else{
	        		break;
				}
			}while(1);
	        
	        return(a);
	    }
	    int *HorizontalSplit()
	    {
	        static int a[2];
	        size1 = 2;
	        DisplayRoulette();
	        
	        do{
	        	cout<<"Enter Your Betting Number For The Split:";
	        	cin>>a[0];
	        	
		        if(a[0]==0){
		        	cout<<"Please Enter A Valid Input....\n";
		        }else{
		        	break;
				}
			}while(1);
			if(a[0]%3==1)
		         a[1]=a[0]+1;
		    else
		         a[1]=a[0]-1;

			cout<<"Your Betting Numbers: "<<a[0]<<" "<<a[1]<<endl;
	        return(a);
	    }
	    int *VerticalSplit()
	    {
	        static int a[2];
	        size1 = 2;
	        DisplayRoulette();
	       	cout<<"Enter Your Betting Number For The Split:";
	        cin>>a[0];
	        if(a[0]==34 || a[0]==35 || a[0]==36)
	         a[1]=a[0]-3;
	        else
	         a[1]=a[0]+3;
	         
	         cout<<"Your Betting Numbers: "<<a[0]<<" "<<a[1]<<endl;
	        return(a);
    	}
    	int *Street()
    	{
	        static int a[3];
	        size1 = 3;
	        DisplayRoulette();
	        do{
	        	cout<<"Enter Your Beting Number:";
	        	cin>>a[0];
	        	
	        	if(a[0]%3!=1){
	            cout<<"Please Enter A Proper Betting Number.....\n";
	        	}else{
	        		break;
				}
			}while(1);
	            for(int i=1;i<3;i++)
	             a[i]=a[i-1]+1;
			             
			cout<<"Your Betting Numbers: "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
			             
		        return(a);
		    }
		    int *Corner()
		    {
		        static int a[4];
		        size1 = 4;
		        DisplayRoulette();
		        
		        do{
			        cout<<"Enter Your Beting Number:";
			        cin>>a[0];
			        	
			        if(a[0]%3==0 || a[0]==34 || a[0]==35 || a[0]==36){
			        cout<<"Please Enter A Proper Betting Number.....\n";
			        }else{
			        	break;
					}
				}while(1);
		       
		        		a[1]=a[0]+1;
		            for(int i=2;i<4;i++)
		             a[i]=a[i-2]+3;
		             
		        cout<<"Your Betting Numbers: "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
		             
		        return(a);
		    }
		    int *TopLine()
		    {
		        static int a[4]={0,1,2,3};
		        size1 = 4;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
		        return(a);
		    }
		    int *DoubleStreet()
		    {
		        static int a[6];
		        size1 = 6;
		        DisplayRoulette();
		         do{
			        cout<<"Enter Your Beting Number 1:";
			        cin>>a[0];
					cout<<"Enter Your Beting Number 2:";
					cin>>a[3];
			        	
			        if(a[0]%3!=1 || a[3]%3!=1){
			        cout<<"Please Enter A Proper Betting Numbers.....\n";
			        }else{
			        	break;
					}
				}while(1);
				
		            for(int i=1;i<3;i++)
		             a[i]=a[i-1]+1;
		            for(int i=3;i<6;i++)
		             a[i]=a[i-1]+1;
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<6;i++){
		        	cout<<" "<<a[i];
				}
		             
		        return(a);
		    }
		
		    int *Column1()
		    {
		        static int a[12]={1,4,7,10,13,16,19,22,25,28,31,34};
		        size1 = 12;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<12;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    int *Column2()
		    {
		        static int a[12]={2,5,8,11,14,17,20,23,26,29,32,35};
		        size1 = 12;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<12;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    int *Column3()
		    {
		        static int a[12]={3,6,9,12,15,18,21,24,27,30,33,36};
		        size1 = 12;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<12;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    int *Dozen1()
		    {
		        static int a[12]={1,2,3,4,5,6,7,8,9,10,11,12};
		        size1 = 12;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<12;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    int *Dozen2()
		    {
		        static int a[12]={13,14,15,16,17,18,19,20,21,22,23,24};
		        size1 = 12;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<12;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    int *Dozen3()
		    {
		        static int a[12]={25,26,27,28,29,30,31,32,33,34,35,36};
		        size1 = 12;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<12;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    int *Odd()
		    {
		        static int a[18]={1,3,5,7,9,11,13,1,17,19,21,23,25,27,29,31,33,35};
		        size1 = 18;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<18;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    int *Even()
		    {
		        static int a[18]={2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36};
		        size1 = 18;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<18;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    int *Red()
		    {
		        static int a[18]={32,19,21,25,34,27,36,30,23,5,16,1,14,9,18,7,12,3};
		        size1 = 18;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<18;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    int *Black()
		    {
		        static int a[18]={15,4,2,17,6,13,11,8,10,24,33,20,31,22,29,28,35,26};
		        size1 = 18;
		        DisplayRoulette();
		        cout<<"Your Betting Numbers: ";   
		        for(int i=0;i<18;i++){
		        	cout<<" "<<a[i];
				}
		        return(a);
		    }
		    void Menu(){
		    	static int *p=0;
		    	cout<<"\n===============================================================================================\n";
		    	cout<<"\t\t\t\tList Of Game Plays";
		    	cout<< "\n===============================================================================================\n";
		    	cout<<"\n1. StraightUp\n2. HorizontalSplit\n3. VerticalSplit\n4. Street\n5. Corner\n6. TopLine\n7. DoubleStreet\n8. Column1\n9. Column2\n"
				    <<"10. Column3\n11. Dozen1\n12. Dozen2\n13. Dozen3\n14. Odd\n15. Even\n16. Red\n17. Black";
				cout<<"\n===============================================================================================\n";
				reenter:
				 	cout<<"\nEnter Your Game Choice:";
					cin>>choice;
					
			    	switch(choice){
			    		case 1:
			    			p = StraightUp();
			    			break;
			    		case 2:
			    			p = HorizontalSplit();
			    			break;
			    		case 3:
			    			p = VerticalSplit();
			    			break;
			    		case 4:
			    			p = Street();
			    			break;
			    		case 5:
			    			p = Corner();
			    			break;
			    		case 6:
			    			p = TopLine();
			    			break;
			    		case 7:
			    			p = DoubleStreet();
			    			break;
			    		case 8:
			    			p = Column1();
			    			break;
			    		case 9:
			    			p = Column2();
			    			break;
			    		case 10:
			    			p = Column3();
			    			break;
			    		case 11:
			    			p = Dozen1();
			    			break;
			    		case 12:
			    			 p = Dozen2();
			    			break;
			    		case 13:
			    			p = Dozen3();
			    			break;
			    		case 14:
			    			p = Odd();
			    			break;
			    		case 15:
			    			p = Even();
			    			break;
			    		case 16:
			    			 p = Red();
			    			break;
			    		case 17:
			    			p = Black();
			    			break;
		    			default:
		    				cout<<"Please Enter A Valid Choice...\n";
		    				goto reenter;
		    				
					} 
				guess1=0;
				cout<<"\n";
				for(int i=0;i<size1;i++){
					//cout<<p[i]<<" ";
					if(wheel==p[i]){
						guess1 = 1;
						break;
					}
				}
				cout<<"\nWheel Number : "<<wheel;
			}
			void welcome(){
				
				cout<< "\n===============================================================================================\n";
				cout<< "\n                               WELCOME TO                                                  ";
				cout<< "\n   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
				cout<< "\n CC          A  A      SS             III     NN N   NN   OO      OO    ";
				cout<< "\nCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    ";
				cout<< "\n CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    ";
				cout<< "\n   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO       ";
				cout<< "\n                         THE NUMBER GUESSING GAME                                             ";
				cout<< "\n                              (ROULETTE)                                                        ";
				cout<< "\n===============================================================================================\n";
				
			}
			
};
int main(){
	casino player;
	player.welcome();
	do{
		cout<<"\nEnter The Number Of Players(MAX UPTO 10):";
		cin>>player.size;
		if(player.size>10 || player.size<1){
			cout<<"\nPlease Enter Only Upto 10...\n";
		}else{
			break;
		}
	}while(1);
	
	player.input();
	player.game();

		cout<< "\n===============================================================================================\n";
		cout<< "\n                        Thanks For Playing Game ";
		player.amountdisplay();
		cout<< "\n===============================================================================================\n";
	return 0;
}
