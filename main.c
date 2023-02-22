#include <stdio.h>
#include <string.h>
struct Contacts{
         char name[50];
         char phone[50];
         char email[50];
         char address[50];
         char occupation[50];
         char gender[50];
}contacts [1001];

struct User{
    char name [50];
    char username [50];
    char email[50];
    char password [50];
    int  Index;
    int NumberOfContacts;

} user [101];

 int ValidUser(char us[50], char pass[50]){
   int k = 0;
    for(int i = 1; i < 101; i++){

      if(!strcmp(user[i].username,us) && !strcmp(user[i].password,pass)) {
         k=i;
         break;
      }
    }
    if(k==0) printf("Invalid username or password.\n");
    return k;
 }
 void AddContact(int k){
    int i = user[k].Index+user[k].NumberOfContacts;
    if (user[k].NumberOfContacts <= 10){
      printf("Name        : ");
      scanf("%s",contacts[i].name);
      printf("Phone       : ");
      scanf("%s",contacts[i].phone);
      printf("Email       : ");
      scanf("%s",contacts[i].email);
      printf("Address     : ");
      scanf("%s",contacts[i].address);
      printf("Occupation  : ");
      scanf("%s",contacts[i].occupation);
      printf("Gender      : ");
      scanf("%s",contacts[i].gender);
      user[k].NumberOfContacts++;
    }
    else printf("No space to add more contacts.\n");
 }

 void ShowContact(int i){
  int start = user[i].Index;
  int end = start+user[i].NumberOfContacts;
  int count = 1;
  printf(" Serial No\t\t Name\t\t Phone\t\t Email\t\t Address\t\t Occupation\t\t Gender\n");
  for(int k = start; k < end; k++){
    printf("%d\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",count,contacts[k].name,contacts[k].phone, contacts[k].email,contacts[k].occupation,contacts[k].address,contacts[k].gender);
    count++;
  }
 }
 void DeleteContact(int i){
   if(user[i].NumberOfContacts==0) printf("No contacts to delete.\n");
   else {
   int start = user[i].Index;
   int DeleteIndex;
   ShowContact(i);
   printf("Enter the contact serial number to delete : ");
   scanf("%d", &DeleteIndex);
   if(DeleteIndex == user[i].NumberOfContacts) user[i].NumberOfContacts--;
   else {
   for(int k = start+DeleteIndex; k < start+user[i].NumberOfContacts; k++){
    contacts[k-1]= contacts[k];
   }
    user[i].NumberOfContacts--;
   }
   printf("After deletion the contact list : \n");
   ShowContact(i);
   printf("\n");
 }
 }

int main (){
    int i = 1,q,c,k;
    while(1){
        printf("Enter\n 1 to Check\n 2 to Exit\n");
        scanf("%d",&q);
        if(q==1){
          while(1){
          printf("Enter\n 1 to Log In\n 2 to Sign Up\n 3 to Exit\n");
          scanf("%d",&c);
          if(c==1){
            char user [50];
            char pass [50];
            printf("Username : ");
            scanf("%s",&user);
            printf("Password : ");
            scanf("%s",&pass);
            int UserSerial = ValidUser(user,pass);
            if(UserSerial){
                  while(1){
                 printf("Enter\n 1 to Add Contact\n 2 to Delete Contact\n 3 to Show Contact\n 4 to Log Out\n");
                 scanf("%d",&k);
                 if(k==1) AddContact(UserSerial);
                 else if(k==2) DeleteContact(UserSerial);
                 else if(k==3) ShowContact(UserSerial);
                 else if(k==4) break;
                 else printf("Invalid Command!\n");
                  }
            }
          }
          else if(c==2){
             printf("\n*** Sign Up ***\n\nName     : ");
             scanf("%s",user[i].name);
             printf("Username : ");
             scanf("%s",user[i].username);
             printf("Email    : ");
             scanf("%s",user[i].email);
             printf("Password : ");
             scanf("%s",user[i].password);
             user[i].Index=(i-1)*10+1;
            printf("\nUser signed up successfully!\n\n");
            i++;
          }
          else if(c==3) break;
          else printf("Invalid Command!\n");
          }
        }
        else if(q==2) break;
        else printf("Invalid Command!\n");
    }
}
