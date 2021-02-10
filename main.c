#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 20 //used in the array

//functions prototypes

void welcome();
void option(int *decision);
void goodbye();
void quiz();
void clear();
void date();
void randomNumber(int *number);
void questions(int *number, int *answer);
void win();
void history();
int question1();
int question2();
int question3();
int question4();
int question5();
int question6();
int question7();
int question8();
int question9();
int question10();

int array[10] = {0}; //global variable

int main() //main function
{
  int decision;

  date(); //displays the actual date and hour
  welcome(); //welcome text
  option(&decision); //option input

  switch(decision) //decision outpu
  {
    case 1: quiz(); // quiz program
            break;
    case 2: clear();
            history(); //winners history program
            break;
    default:  goodbye(); //goodbye text
              exit(0); //exit from program
  }

  win(); //win text

  return 0;
}

void welcome() //welcome text
{
  printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
  printf("\n\t\t\t\t~ $ WELCOME TO MY QUIZ GAME $ ~");
  printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
  printf("\n\n\n\n\t\t  Answer three questions correctly, and you will be remebered!\n");
  printf("\t\t  ------------------------------------------------------------\n\n");
  printf("\n\n\t\t\t\t\t1. Start now!\n\t\t\t\t\t2. History\n\t\t\t\t\t3. Leave.\n\t\t\n\n\t\t\t\t\tChoice: ");
}

void option(int * decision) //we get user's decision
{
  scanf("%d",&*decision);
}

void goodbye() //goodbye text
{
  clear();
  printf("\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
  printf("\n\t\t\t~\t      GOOD LUCK NEXT TIME!\t      ~\n\t\t\t~ YOU WILL BE REMEMBERED.. BUT NOT AS WINNER! ~");
  printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n\n");
}

void clear() //function that clears screen according to the operating system
{
  #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
  #endif

  #if defined(_WIN32) || defined(_WIN64)
    system("cls");
  #endif
}

void quiz() //quiz main program
{
  int number, answer, wins = 0, counter = 1;

  clear();
  date();

  while(wins < 1){
    printf("\n\n\t\t\t\t    Question %d: \n\t\t\t\t   ^^^^^^^^^^^^^",counter);
    randomNumber(&number); //generates random number in order to avoid question repitition
    questions(&number,&answer);
    if(answer == 1){  //if the answer is correct
      wins++;
      counter++; // question number counter
    }
  }
}

void history()
{
  char characterFile; //we take each character from the .csv file
  int leaveDecision; //user decision- leaving or not

  clear();
  date();
  printf("\n\n\t\tLegends say that Giulio Cesare played this quiz as well..\n\t\t            but here's our winners history:\n\t\t---------------------------------------------------------");

  FILE *fp;
  fp = fopen("Whistory.csv", "r");

  if(fp == NULL){
    printf("Can't Open!\n");
    return 1;
  }
  printf("\n\n\nName, Country: ");

  while(!feof(fp)) {
    fscanf(fp,"%c",&characterFile);
    if(characterFile == ',' ){
      printf(",");
      continue;
    }
    printf("%c",characterFile);
  }

  printf("\n\n\t\tYou better play next time if you want to be in our history!\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

  fclose(fp);

  printf("\n\n\t\t\t\tDo you want leave?\n\n\t\t\t\t1. YES\n\t\t\t\t2. MAIN MENU\n\n\t\t\t\tDecision: ");
  scanf("%d",&leaveDecision);

  if(leaveDecision == 1) {
    clear();
    printf("\n\n\t\t\t\tSee you next time!!\n\t\t\t\t^^^^^^^^^^^^^^^^^^\n\n\n");
    exit(0);
  }
  else{
    clear();
    main();
  }
}

void randomNumber(int *number) //generates random number in order to avoid question repitition
{
  int min = 1, max = 10;

  while(1){
    srand(time(NULL));
    *number= (rand() % (max-min+1) + min); //number generation
    if( array[*number-1] == 0) { //checking if the number has already been used
      array[*number-1] = 1; //as the number has not been used before, we mark it as used in the array
      break;
    }
    else //otherwise generates the number once again
      continue;
  }
}

void date() //prints the actual date/hour
{
  time_t now;
  time(&now);

  printf(" %s",ctime(&now));
}

void questions(int *number, int *answer) //as we get the generated number, we will open the respective quiestionX function
{
  switch(*number){
    case 1: *answer = question1();
            break;
    case 2: *answer = question2();
            break;
    case 3: *answer = question3();
            break;
    case 4: *answer = question4();
            break;
    case 5: *answer = question5();
            break;
    case 6: *answer = question6();
            break;
    case 7: *answer = question7();
            break;
    case 8: *answer = question8();
            break;
    case 9: *answer = question9();
            break;
    case 10: *answer = question10();
            break;
  }
}

void win() //win text
{
  int answer1;
  char name[N], surname[N], country[N];

  printf("\n\n\t\tEASY VICTORY. YOU WILL BE FOREVER REMEMBERED..IN OUR WINNERS HISTORY FILE!\n\n\t\tWHAT'S YOUR NAME: ");
  scanf("%s",name);
  printf("\n\t\tSURNAME: ");
  scanf("%s",surname);
  printf("\n\t\tCOUNTRY: ");
  scanf("%s",country);

  FILE *fp1;
  fp1 = fopen("Whistory.csv", "a");

  if(fp1 == NULL){
    printf("Can't open!\n");
    return 1;
  }

  fprintf(fp1,"\n%s %s,%s ",name,surname,country);
  fclose(fp1);

  printf("\n\n\t\tYOU HAVE BEEN ADDED TO OUR HISTORY! MAKE SURE TO CHECK IT OUT!\n\n\n\t\tSEE HISTORY [1]  or  EXIT  [2]\n\n\t\tDecision: ");
  scanf("%d",&answer1);
  if(answer1 == 1) {
    clear();
    history();
  }
  else{
    clear();
    printf("\n\n\t\t\t\tSee you next time!!\n\t\t\t\t^^^^^^^^^^^^^^^^^^\n\n\n");
    exit(0);
  }
}

int question1()
{
  int answerQuestion;

  printf("\n\n\n\t\t\tWhat is the capital of Burkina Faso?\n\n\n\t\t\t1. BAMAKO\t\t2. OUAGADOUGOU\n\t\t\t3. NIAMEY\t\t4. NEW DELHI\n\n\t\t\t\t    Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 2) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}

int question2(){

  int answerQuestion;

  printf("\n\n\n\t\t\t    PUGNA,PUGNAE in Latin means: \n\n\n\t\t\t    1. WORK\t\t2. SLEEP\n\t\t\t    3. BATTLE\t\t4. SWORD\n\n\t\t\t\t     Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 3) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}

int question3()
{
  int answerQuestion;

  printf("\n\n\n\t\t      How many stripes are there on the US flag? \n\n\t\t      1. Nine\t\t\t       2. Eleven\n\t\t      3. Thirteen\t\t       4. Fourteen\n\n\t\t\t\t      Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 3) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}

int question4()
{
  int answerQuestion;

  printf("\n\n\n\t\t What is the slang name for New York City, used by locals? \n\n\t\t 1. GOTHAM\t\t\t\t     2. MERSEYSIDE\n\t\t 3. MAGIC CITY\t\t\t\t     4. SIN CITY\n\n\t\t\t\t      Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 1) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}

int question5()
{
  int answerQuestion;

  printf("\n\n\n\t\t\t   What happened on July 20th, 1969? \n\n\t\t1. PUTIN BECAME PRESIDENT\t2. APOLLO 11 LANDED NO THE MOON\n\t\t3. FIRST COMPUTER\t\t4. FIRST TELEPHONE\n\n\t\t\t\t     Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 2) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}

int question6()
{
  int answerQuestion;

  printf("\n\n\n\t\t\t  Name the longest river in the world? \n\n\t\t\t  1. THE NILE\t\t  2. MISSOURI\n\t\t\t  3. MISSISSIPPI\t  4. RIO GRANDE\n\n\t\t\t\t     Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 1) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}

int question7()
{
  int answerQuestion;

  printf("\n\n\n\t\tWho scored the first Premier League hat-trick?(Football) \n\n\t\t1. CANTONA\t\t\t\t      2. CRUYFF\n\t\t3. GIGGS\t\t\t\t      4. BECKHAM\n\n\t\t\t\t     Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 1) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}

int question8()
{
  int answerQuestion;

  printf("\n\n\n\t\t\t      Where was Napoleon born? \n\n\t\t\t    1. ITALY\t       2. BELGIUM\n\t\t\t    3. CORSICA\t       4. FRANCE\n\n\t\t\t\t     Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 3) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}

int question9()
{
  int answerQuestion;

  printf("\n\n\n\t\t\tWho was the first president of the USA?	 \n\n\t\t\t1. CHURCHILL\t\t  2. ADAMS\n\t\t\t3. MADISON\t\t  4. WASHINGTON\n\n\t\t\t\t      Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 4) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}

int question10()
{
  int answerQuestion;

  printf("\n\n\n\t\t  Which country is the largest producer of olive oil?	 \n\n\t\t  1. ITALY\t\t\t\t    2. SPAIN\n\t\t  3. FRANCE\t\t\t\t    4. GREECE\n\n\t\t\t\t     Answer: ");
  scanf("%d",&answerQuestion);

  if(answerQuestion == 2) { //if the question is correct, return 1
    clear();
    printf("\n\n\t\tCorrect answer!\n\t\t---------------");
    return 1;
  }
  else { //otherwise leave the program
    clear();
    printf("\n\n\tWrong answer. But remember, the program is free. You can try once again!\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n");
    exit(0);
  }
}
