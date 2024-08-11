#include<stdio.h>
#include<conio.h>
#include<string.h>
void login();
void signup();
int order();
void bill();
typedef struct dishes{
			char food[10][20];
			int price[10];
			}dishes;

int main(){

char question[20];

	printf("Do you already have an account:");
	scanf("%s",&question);
	if(strcmp(question,"no")==0){
	signup();
	goto login_page;
	}
	if(strcmp(question,"yes")==0){
	login_page:
	login();
	}
getch();
return 0;
}

void signup(){
FILE *data;
char signup_username[20],signup_password[20],signup_check_password[20],signup_check_username[20];
printf("******************** Signup Page ********************\n");
signup:
printf("Enter username:");
scanf("%s",&signup_username);
printf("Enter password:");
scanf("%s",&signup_password);
data=fopen("login.txt","r");
while(fscanf(data,"%s\t%s\n",signup_check_username,signup_check_password)!=-1){
if(strcmp(signup_check_username,signup_username)==0&&strcmp(signup_check_password,signup_password)==0){
printf("Username and Password already used\n");
goto signup;
}
}
fclose(data);
data_input:
data=fopen("login.txt","a");
fprintf(data,"%s\t%s\n",signup_username,signup_password);
fclose(data);
}


void login(){
FILE *data;
int count=0;
char username[20],password[20],login_username[20],login_password[20];
printf("******************** login Page ********************\n");
login:
printf("Enter username:");
scanf("%s",&username);
printf("Enter password:");
scanf("%s",&password);
data=fopen("login.txt","r");
if(data==NULL){
signup();
}
while(fscanf(data,"%s\t%s\n",login_username,login_password)!=-1){
if(strcmp(username,login_username)==0&&strcmp(password,login_password)==0){
printf("login sucessful\n");
order();
count=count++;
}
}
if(count==0){
printf("Invalid Username or Password\n");
goto login;
}
}


int order(){
int i,n=0;
int num=0,choice,serving;
long int total[50],totalall=0;
char choice_detail[10][20],answer[3];
int choice_price[20],choice_qty[20];
dishes m[1];
strcpy(m[0].food[0],"Pizza       ");
strcpy(m[0].food[1],"Burger      ");
strcpy(m[0].food[2],"Momo        ");
strcpy(m[0].food[3],"Chowmein    ");
strcpy(m[0].food[4],"Kathi roll  ");
strcpy(m[0].food[5],"Pani puri   ");
strcpy(m[0].food[6],"French fries");
strcpy(m[0].food[7],"Samosas     ");
strcpy(m[0].food[8],"chatamari   ");
strcpy(m[0].food[9],"Khaja set   ");
m[0].price[0]=800;
m[0].price[1]=300;
m[0].price[2]=150;
m[0].price[3]=150;
m[0].price[4]=200;
m[0].price[5]=100;
m[0].price[6]=80;
m[0].price[7]=45;
m[0].price[8]=100;
m[0].price[9]=300;
printf("******************************* Home Page *******************************\n\n");
printf("You are successfully logged in\n");
printf("Welcome to food ordering system\n");
l2:
	for(i=0;i<=9;i++){
		num=i+1;
		printf("%d) %s\n",num,m[0].food[i]);
	}
	printf("%d) Bill\n",num+1);
	printf("%d) Exit\n",num+2);
	printf("\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	if(choice<=10){
	printf("Enter nurber of serving:");
	scanf("%d",&serving);
	}

switch(choice){
	case 1:{
		strcpy(choice_detail[n],m[0].food[0]);
		choice_price[n]=m[0].price[0];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 2:{
		strcpy(choice_detail[n],m[0].food[1]);
		choice_price[n]=m[0].price[1];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 3:{
		strcpy(choice_detail[n],m[0].food[2]);
		choice_price[n]=m[0].price[2];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 4:{
		strcpy(choice_detail[n],m[0].food[3]);
		choice_price[n]=m[0].price[3];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 5:{
		strcpy(choice_detail[n],m[0].food[4]);
		choice_price[n]=m[0].price[4];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 6:{
		strcpy(choice_detail[n],m[0].food[5]);
		choice_price[n]=m[0].price[0];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 7:{
		strcpy(choice_detail[n],m[0].food[6]);
		choice_price[n]=m[0].price[6];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 8:{
		strcpy(choice_detail[n],m[0].food[7]);
		choice_price[n]=m[0].price[7];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 9:{
		strcpy(choice_detail[n],m[0].food[8]);
		choice_price[n]=m[0].price[8];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 10:{
		strcpy(choice_detail[n],m[0].food[9]);
		choice_price[n]=m[0].price[9];
		choice_qty[n]=serving;
		n=n+1;
		goto l2;
		}
	case 11:{
		printf("\n");
		printf("\t\t\t\tBill\n");
		printf("Food items\t\tQuantity\t\tprice per qty\t\ttotal\n");

		for(i=0;i<n;i++){
		total[i]=(long int)choice_price[i]*(long int)choice_qty[i];
		printf("%s\t\t%d\t\t\t%d\t\t\t%ld\n",choice_detail[i],choice_qty[i],choice_price[i],total[i]);
		totalall=totalall+total[i];
		}
		printf("\t\t\t\t\t\t\t\t total=%ld\n",totalall);
		printf("Do yo wish to exit:");
		scanf("%s",&answer);
		if(strcmp(answer,"yes")==0){
			 break;
			 }
		else{
		goto l2;
		}
		}

	case 12:{
		printf("Thankyou for ordering our food");
		return 1;
		}
	default:{
	printf("please choose the correct choice\n");
		goto l2;
		}
}
return 0;
}
