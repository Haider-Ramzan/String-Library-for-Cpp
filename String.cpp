#include <iostream>
using namespace std;

class String{
    // think about the private data members...
    private:

    int length;
    char * ch_arr;

    public:
    // provide definitions of following functions...
    String(); // a default constructor ---------------------------------------------------------------------------------
    String(const char*); //---------------------------------------------------------------------------------------------
    String(const String&); //-----------------------------------------------------------------------------------------
    String add(const String&); // appends a String to the end //returns a new string doesn't change the original string  --------------------------------------------------------
    String add(const char*); // appends a String to the end //returns a new string doesn't change the original string --------------------------------------------------------
    String add(char*); // appends a String to the end //returns a new string doesn't change the original string--------------------------------------------------------
    String add(const int&); // if the stored String is an integer e.g. “123” it adds the given integer into it and returns the answer. If not then returns “NaN” //returns a new string doesn't change the original string----------------------------
    String remove(const String&); //removes a substring anywhere in the String //returns a new string doesn't change the original string----------------------------------------------------------------
    String remove(const char*); //removes a substring anywhere in the String //returns a new string doesn't change the original string-------------------------------------------------------
    String remove(char*); //removes a substring anywhere in the String //returns a new string doesn't change the original string-------------------------------------------------------
    String remove(const int&); // if the stored String is an integer e.g. “123” it subtracts the given integer into it and returns the answer. If not then returns “NaN” //returns a new string doesn't change the original string
    bool equal(const String&)const;//--------------------------------------------------------------------------------------------------------------
    bool equal(const char *)const; //--------------------------------------------------------------------------------------------------------------
    bool equal(char *)const; //--------------------------------------------------------------------------------------------------------------
    bool operator!(); //--------------------------------------------------------//--------------------------------------------------------
    void addnew(const String&); //appends a new string into the same string //--------------------------------------------------------
    void removesub(const String&); // removes the substring from the same string//--------------------------------------------------------
    
    
    String slice(const String&); // Performs slicing according to explanation below
    String slice(const char *); // Performs slicing according to explanation below

    String helperReverseString();
    String helperReturningTheSicingRequired(int, int, int);

    int len();// returns length ------------------------------------------------------------------------------------------------
    String lower();//---------------------------------------//---------------------------------------
    String upper();//---------------------------------------//---------------------------------------
    String title();//---------------------------------------//---------------------------------------
    String swapcase();//---------------------------------------//---------------------------------------//---------------------------------------
    bool startsWith(const char*);//---------------------------------------//---------------------------------------
    bool startsWith(String& );//---------------------------------------//---------------------------------------
    bool endsWith(const char*);//---------------------------------------//---------------------------------------
    bool endsWith(String&);//---------------------------------------//---------------------------------------
    String replace(String&, String&); //---------------------------------------//---------------------------------------
    String replace(const char *, const char *);//---------------------------------------//---------------------------------------
    String join(String&); //---------------------------------------//---------------------------------------//---------------------------------------
    String join(const char *);//---------------------------------------//---------------------------------------
    String join(char *);//---------------------------------------//---------------------------------------
    String* split(String&, int &size);
    String* split(const char *, int &size);
    String* split(char *, int &size);

    //the below operator was needed so that i can make DEEP copies and avoid the destruction of shallow copies in my split function
    void operator = (String & str){
        length = str.length;
        ch_arr = new char [str.length+1];

        for(int i =0; i<length; i++){
            ch_arr[i] = str.ch_arr[i];
        }
        ch_arr[length] = '\0';

    }
    //display function:
    void display(){
        for(int i =0; i<length; i++){
            cout<<ch_arr[i];
        }
        if(length>0){
            cout<<endl;
        }
        
    }
    ~String(); // destructor...
};

//--------------------------------------------------------------------------------------------------------
//---------------------------------------------->Constructors<--------------------------------------------
//--------------------------------------------------------------------------------------------------------
String :: String() {
    length =0;
    ch_arr = new char[1];
    ch_arr[0] = '\0';
}

String :: String(const char*temp){

    int length = 0;
    for(int i =0; temp[i] !='\0'; i++){
        length++;
    }

    this -> length = length;

    ch_arr = new char[length +1]; //1 extra for null

    for(int i =0; temp[i] !='\0'; i++){
        ch_arr[i]=temp[i];
    }
    ch_arr[length]='\0';

}

String::String(const String& str){
    length = str.length;

    ch_arr = new char[length+1];

    for(int i=0; i<length+1;i++){ // +1 for null
        ch_arr[i] = str.ch_arr[i];
    }
}


//--------------------------------------------------------------------------------------------------------
//--------------------------------------------->Length Function<------------------------------------------
//--------------------------------------------------------------------------------------------------------
int String :: len(){
    return length;
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------->Equal Checkers<-------------------------------------------
//--------------------------------------------------------------------------------------------------------
bool String :: equal(const String& str)const{

    
    if(str.length!= length){ // if lengths are not equal then string not equal sso return 0
        return 0;
    }

    for(int i = 0; ch_arr[i]!='\0'; i++){
        if(str.ch_arr[i] != ch_arr[i]){
            return 0;
        }
    }
    return 1;

}

bool String:: equal(const char * temp)const{

    int temp_length =0;
    for(int i =0; temp[i]!= '\0'; i++){
        temp_length++;
    }

    if(temp_length != length){
        return 0;
    }

    for(int i = 0; ch_arr[i]!='\0'; i++){
        if(temp[i] != ch_arr[i]){
            return 0;
        }
    }

    return 1;
}

bool String :: equal(char * temp)const{

    int temp_length =0;
    for(int i =0; temp[i]!= '\0'; i++){
        temp_length++;
    }

    if(temp_length != length){
        return 0;
    }

    for(int i = 0; ch_arr[i]!='\0'; i++){
        if(temp[i] != ch_arr[i]){
            return 0;
        }
    }

    return 1;

} 


//--------------------------------------------------------------------------------------------------------
//--------------------------------------------->ADD Functions<--------------------------------------------
//--------------------------------------------------------------------------------------------------------

String String :: add(const String& str){

    String new_str_to_return(ch_arr);

    int org_length = new_str_to_return.length;
    new_str_to_return.length = new_str_to_return.length + str.length; 

    char * ptr = new char [new_str_to_return.length+1]; // +1 for null

    int index=0;
    for(int i=0; i<org_length; i++){
        ptr[index] = new_str_to_return.ch_arr[i]; 
        index++;
    }

    for(int i =0; i<str.length; i++){
        ptr[index] = str.ch_arr[i];
        index++;
    }

    ptr[index] = '\0';

    delete [] new_str_to_return.ch_arr;

    
    new_str_to_return.ch_arr = ptr; // making new_str_to_return.ch_arr equal to ptr, no need to make a new ch_arr, i just made these both aliases.

    return new_str_to_return;

} 

String String :: add(const char* temp){

    String new_str_to_return(ch_arr);

    int temp_length =0;
    for(int i =0; temp[i]!= '\0'; i++){
        temp_length++;
    }


    int org_length = new_str_to_return.length;
    new_str_to_return.length = new_str_to_return.length + temp_length; 

    char * ptr = new char [new_str_to_return.length+1]; // +1 for null

    int index=0;
    for(int i=0; i<org_length; i++){
        ptr[index] = new_str_to_return.ch_arr[i]; 
        index++;
    }

    for(int i =0; i<temp_length; i++){
        ptr[index] = temp[i];
        index++;
    }

    ptr[index] = '\0';

    delete [] new_str_to_return.ch_arr;


    new_str_to_return.ch_arr = ptr;  // making new_str_to_return.ch_arr equal to ptr

    return new_str_to_return;

} 

String String :: add(char*temp){

    String new_str_to_return(ch_arr);

    int temp_length =0;
    for(int i =0; temp[i]!= '\0'; i++){
        temp_length++;
    }


    int org_length = new_str_to_return.length;
    new_str_to_return.length = new_str_to_return.length + temp_length; 

    char * ptr = new char [new_str_to_return.length+1]; // +1 for null

    int index=0;
    for(int i=0; i<org_length; i++){
        ptr[index] = new_str_to_return.ch_arr[i]; 
        index++;
    }

    for(int i =0; i<temp_length; i++){
        ptr[index] = temp[i];
        index++;
    }

    ptr[index] = '\0';

    delete [] new_str_to_return.ch_arr;

    new_str_to_return.ch_arr = ptr; // making ch_arr equal to ptrr

    return new_str_to_return;
}

String String :: add(const int& num){

    String new_str_to_return(ch_arr);

    for(int i =0; new_str_to_return.ch_arr[i]!='\0'; i++){

        if((new_str_to_return.ch_arr[i] > '9') || (new_str_to_return.ch_arr[i] < '0')){
            return String("NaN"); // returning a string with NaN written
        }
    }

    long long int ch_num =0;

    for(int i =0; new_str_to_return.ch_arr[i]!='\0' ; i++){
        ch_num *=10;
        ch_num += new_str_to_return.ch_arr[i] - '0';
    }

    ch_num += num;

    delete [] new_str_to_return.ch_arr;

    int temp= ch_num;
    
    int size = (temp == 0) ? 1 : 0; // Handling edge case for 0 
    for(int i =0; temp!= 0; i++){
        temp/=10;
        size++; // calculates size, even if digits increase, this will calculate
    }

    new_str_to_return.length = size;
    new_str_to_return.ch_arr = new char [new_str_to_return.length +1]; // +1 for nll

    for(int i=new_str_to_return.length-1; i>=0 ; i--){
        new_str_to_return.ch_arr[i] = ch_num%10 + '0';
        ch_num /= 10;
    }

    new_str_to_return.ch_arr[new_str_to_return.length]= '\0';


    return new_str_to_return;
} 

//--------------------------------------------------------------------------------------------------------
//-------------------------------------------->Remove Functions<------------------------------------------
//--------------------------------------------------------------------------------------------------------

String String :: remove(const String& str){

    String new_str_to_return(*this);
    /*in this i am making an array and this through traversing i will find all the starting indexes
    if the particular string exists in the the string which we need to remove. Then in ptr
    we add all the data except those indexes+ length of the removing string.*/

    if(str.ch_arr[0] == '\0'){ // might be an edge case;
        return new_str_to_return;
    }

    //the below loop finds the max size that the indexes could have;
    int max_size_possible=0;
    for(int i = 0; i<new_str_to_return.length; i++){
        if(new_str_to_return.ch_arr[i] == str.ch_arr[0]){
            max_size_possible++;
        }
    }
    int * index_arr=new int [max_size_possible];

    int arr_index=0;

    for(int i =0; i<new_str_to_return.length; i++){

        if(new_str_to_return.ch_arr[i] == str.ch_arr[0]){

            int index =i;
            bool flag =1;
            for(int j=0; str.ch_arr[j]!='\0';j++ ){

                if(new_str_to_return.ch_arr[index] != str.ch_arr[j]){
                    flag =0;
                    break;
                }

                index ++;
            }
            if(flag){
                index_arr[arr_index] = i;
                arr_index++;
                i+=str.length-1; // so that the next char which are tobe removed are skipped
            }
        }
    }

    int new_length = new_str_to_return.length - arr_index*str.length;
    char * ptr = new char[new_length+1];

    int index=0;
    for(int i =0; new_str_to_return.ch_arr[i]!='\0'; ){

        bool flag =1;
        
        for(int j=0; j<arr_index; j++){

            if(i == index_arr[j]){
                flag =0;
            }

        }

        if(!flag){ //if flag is zero
            i+=str.length;
            continue;
        }
        else{
            ptr[index] = new_str_to_return.ch_arr[i];
            index++;
        }
        
        i++;
    }

    ptr[index] = '\0';

    delete [] new_str_to_return.ch_arr;
    new_str_to_return.ch_arr = NULL;

    new_str_to_return.ch_arr = ptr;
    new_str_to_return.length=new_length;

    delete [] index_arr;

    return new_str_to_return;

}
String String :: remove(const char* temp){

    String new_str_to_return(*this);

    if(temp[0]== '\0'){ // might be an edge case;
        return new_str_to_return;
    }

    //finding temp length
    int temp_length =0;
    for(int i =0; temp[i]!='\0'; i++){
        temp_length++;
    }
    
    //the below loop finds the max size that the indexes could have;
    int max_size_possible=0;
    for(int i = 0; i<new_str_to_return.length; i++){
        if(new_str_to_return.ch_arr[i] == temp[0]){
            max_size_possible++;
        }
    }
    int * index_arr=new int [max_size_possible];

    int arr_index=0;

    for(int i =0; i<new_str_to_return.length; i++){

        if(new_str_to_return.ch_arr[i] == temp[0]){

            int index =i;
            bool flag =1;
            for(int j=0; temp[j]!='\0';j++ ){

                if(new_str_to_return.ch_arr[index] != temp[j]){
                    flag =0;
                    break;
                }

                index ++;
            }
            if(flag){
                index_arr[arr_index] = i;
                arr_index++;
                i+=temp_length-1; // so that the next char which are tobe removed are skipped
            }
        }
    }

    

    int new_length = new_str_to_return.length - arr_index*temp_length;
    char * ptr = new char[new_length+1];

    int index=0;
    for(int i =0; new_str_to_return.ch_arr[i]!='\0'; ){

        bool flag =1;
        
        for(int j=0; j<arr_index; j++){

            if(i == index_arr[j]){
                flag =0;
            }

        }

        if(!flag){ //if flag is zero
            i+=temp_length;
            continue;
        }
        else{
            ptr[index] = new_str_to_return.ch_arr[i];
            index++;
        }
        
        i++;
    }

    ptr[index] = '\0';

    delete [] new_str_to_return.ch_arr;
    new_str_to_return.ch_arr = NULL;

    new_str_to_return.ch_arr = ptr;
    new_str_to_return.length=new_length;

    delete [] index_arr;

    return new_str_to_return;
} 
String String :: remove(char* temp){
    String new_str_to_return(*this);

    if(temp[0]== '\0'){ // might be an edge case;
        return new_str_to_return;
    }

    //finding temp length
    int temp_length =0;
    for(int i =0; temp[i]!='\0'; i++){
        temp_length++;
    }
    
    //the below loop finds the max size that the indexes could have;
    int max_size_possible=0;
    for(int i = 0; i<new_str_to_return.length; i++){
        if(new_str_to_return.ch_arr[i] == temp[0]){
            max_size_possible++;
        }
    }
    int * index_arr=new int [max_size_possible];

    int arr_index=0;

    for(int i =0; i<new_str_to_return.length; i++){

        if(new_str_to_return.ch_arr[i] == temp[0]){

            int index =i;
            bool flag =1;
            for(int j=0; temp[j]!='\0';j++ ){

                if(new_str_to_return.ch_arr[index] != temp[j]){
                    flag =0;
                    break;
                }

                index ++;
            }
            if(flag){
                index_arr[arr_index] = i;
                arr_index++;
                i+=temp_length-1; // so that the next char which are tobe removed are skipped
            }
        }
    }

    

    int new_length = new_str_to_return.length - arr_index*temp_length;
    char * ptr = new char[new_length+1];

    int index=0;
    for(int i =0; new_str_to_return.ch_arr[i]!='\0'; ){

        bool flag =1;
        
        for(int j=0; j<arr_index; j++){

            if(i == index_arr[j]){
                flag =0;
            }

        }

        if(!flag){ //if flag is zero
            i+=temp_length;
            continue;
        }
        else{
            ptr[index] = new_str_to_return.ch_arr[i];
            index++;
        }
        
        i++;
    }

    ptr[index] = '\0';

    delete [] new_str_to_return.ch_arr;
    new_str_to_return.ch_arr = NULL;

    new_str_to_return.ch_arr = ptr;
    new_str_to_return.length=new_length;

    delete [] index_arr;

    return new_str_to_return;
} 
String String :: remove(const int& num){

    String new_str_to_return(*this);

    /*just copy pasted the add function and change + to - in ch_num+=num;*/

    for(int i =0; new_str_to_return.ch_arr[i]!='\0'; i++){

        if((new_str_to_return.ch_arr[i] > '9') || (new_str_to_return.ch_arr[i] < '0')){
            return String("NaN"); // returning a string with NaN written
        }
    }

    long long int ch_num =0;

    for(int i =0; new_str_to_return.ch_arr[i]!='\0' ; i++){
        ch_num *=10;
        ch_num += new_str_to_return.ch_arr[i] - '0';
    }

    ch_num -= num; // changed to minus here

    delete []new_str_to_return.ch_arr;

    int temp= ch_num;
    
    int size = (temp == 0) ? 1 : 0; // Handling edge case for 0 
    for(int i =0; temp!= 0; i++){
        temp/=10;
        size++; // calculates size, even if digits increase, this will calculate
    }

    new_str_to_return.length = size;
    new_str_to_return.ch_arr = new char [new_str_to_return.length +1]; // +1 for nll

    for(int i=new_str_to_return.length-1; i>=0 ; i--){
        new_str_to_return.ch_arr[i] = ch_num%10 + '0';
        ch_num /= 10;
    }

    new_str_to_return.ch_arr[new_str_to_return.length]= '\0';


    return new_str_to_return;

}


//--------------------------------------------------------------------------------------------------------
//----------------------------------------------->! operator<---------------------------------------------
//--------------------------------------------------------------------------------------------------------

bool String :: operator!(){

    if(ch_arr[0] == '\0'){
        return true;
    }

    return false;
} 


//--------------------------------------------------------------------------------------------------------
//-------------------------------------------->Add New Function<------------------------------------------
//--------------------------------------------------------------------------------------------------------

void String:: addnew(const String& str){
    
    int org_length = length;
    length = length + str.length; 

    char * ptr = new char [length+1]; // +1 for null

    int index=0;
    for(int i=0; i<org_length; i++){
        ptr[index] = ch_arr[i]; 
        index++;
    }

    for(int i =0; i<str.length; i++){
        ptr[index] = str.ch_arr[i];
        index++;
    }

    ptr[index] = '\0';

    delete [] ch_arr;

    
    ch_arr = ptr; // making ch_arr equal to ptr, no need to make a new ch_arr, i just made these both aliases.
} 
    

//--------------------------------------------------------------------------------------------------------
//------------------------------------------->Remove Sub Function<----------------------------------------
//--------------------------------------------------------------------------------------------------------

void String::removesub(const String& str){
     /*in this i am making an array and this through traversing i will find all the starting indexes
    if the particular string exists in the the string which we need to remove. Then in ptr
    we add all the data except those indexes+ length of the removing string.*/

    if(str.ch_arr[0] == '\0'){ // might be an edge case;
        return ;
    }

    //the below loop finds the max size that the indexes could have;
    int max_size_possible=0;
    for(int i = 0; i<length; i++){
        if(ch_arr[i] == str.ch_arr[0]){
            max_size_possible++;
        }
    }
    int * index_arr=new int [max_size_possible];

    int arr_index=0;

    for(int i =0; i<length; i++){

        if(ch_arr[i] == str.ch_arr[0]){

            int index =i;
            bool flag =1;
            for(int j=0; str.ch_arr[j]!='\0';j++ ){

                if(ch_arr[index] != str.ch_arr[j]){
                    flag =0;
                    break;
                }

                index ++;
            }
            if(flag){
                index_arr[arr_index] = i;
                arr_index++;
            }
        }
    }

    int new_length = length - arr_index*str.length;
    char * ptr = new char[new_length+1];

    int index=0;
    for(int i =0; ch_arr[i]!='\0'; ){

        bool flag =1;
        
        for(int j=0; j<arr_index; j++){

            if(i == index_arr[j]){
                flag =0;
            }

        }

        if(!flag){ //if flag is zero
            i+=str.length;
            continue;
        }
        else{
            ptr[index] = ch_arr[i];
            index++;
        }
        
        i++;
    }

    ptr[index] = '\0';

    delete [] ch_arr;
    ch_arr = NULL;

    ch_arr = ptr;
    length=new_length;

    delete [] index_arr;

}


//--------------------------------------------------------------------------------------------------------
//-------------------------------------------->Slicing Functions<-----------------------------------------
//--------------------------------------------------------------------------------------------------------

String String :: helperReturningTheSicingRequired(int start_index, int end_index, int skips=1){

    //cout<<"Start: "<<start_index<<endl<<"End:"<<end_index<<endl<<"Skips: "<<skips<<endl;//debugging
    String temp;
    
    temp.length = 0;

    if(skips<0){ // negative steps

        skips *=-1; //making skips positive

        for(int i =start_index; i>end_index; i-=skips){
            temp.length++;
        }
    
        temp.ch_arr = new char [temp.length +1]; // +1 for null

        int index=0;
        for(int i=start_index; i>end_index; i-=skips){ // i iterates till end_index and not temp.length as we need to reach end index and number of iterations are affected by skips nit the condition.
            temp.ch_arr[index] = ch_arr[i];
            index++;
        }

        temp.ch_arr[temp.length] = '\0';

        return temp;
    }

    for(int i =start_index; i<end_index; i+=skips){
        temp.length++;
    }

    
    
    temp.ch_arr = new char [temp.length +1]; // +1 for null

    int index=0;
    for(int i=start_index; i<end_index; i+=skips){ // i iterates till end_index and not temp.length as we need to reach end index and number of iterations are affected by skips nit the condition.
        temp.ch_arr[index] = ch_arr[i];
        index++;
    }

    temp.ch_arr[temp.length] = '\0';
    return temp;

}

String String :: slice(const String& str){

    // this function will work for all cases except if steps are negative except for steps ==-1;

    /*start:stop:steps
    this is the genral formula
    if only onne colon then steps are considerd as defaultly one;
    1)start means to start FROM that index e.g 2 means the 3rd postion.
    2)stop means to stop BEFORE that index e.g 4 means to end before 5th postion
    3) steps mean how many steps to move forward after each charachter */

    if(str.ch_arr[0]== '\0'){
        cout<<"Invalid SLicing"<<endl;
        return String("");
    }

    //checking if there even is a colon in the code
    bool colon_exists= false;
    for(int i =0; str.ch_arr[i]!='\0';i++){
        if(str.ch_arr[i]==':'){
            colon_exists=true;
        }
    }

    if(!colon_exists){ // if there is no colon in the slicing
        return String("");
    }

    // if(str.equal("::-1")){

    //     if(str.ch_arr[0] =='\0'){
    //         return String("");
    //     }
        
    //     return helperReverseString();
    // }
    /*how does my code work???
    so first of all i start traversing through the slicing array which contains the type of slicing we need
    to do.
    then i add up the numbers till first colon. if numbers on't exist, then the default 0 is added
    to the start variable. as now starting position is from start.
    
    then after first colon the second condition is run as it's flag is turned on and first conditon flag is off.
    so when we reach the second colon, the second condition includes all the data of num to 
    end as second position offers the ending index. if doesn't exist then the default of length
    is written to end variable.
    is the second colon doesnot exist then after loop ends, we wimply write the number to end
    and same procedure. we also makesteps one.
    
    then after the second colon we count the numbers and if they are not present then
    stepss is defaultly made one. or else steps are made the number. 
    
    in the loop we also check if any extra character has come in the array, in that case Wrong characters
    is printed and the string is returned without any change. 
    
    if a negative sign comes then it can only exist with start or end. so i have made
    flags for that too. if minus exists then they are made true.
    
    then after the loop the conditions are checked.
    first is that start should be less than the length and end should be less than length or equal to.
    
    then if negative start or stop are there then that case is handled by subtracting start and stop with 
    the length. 
    
    After this simply the function is called which will write make the String temp, and return it.*/

    int num =0;
    int start=0;
    int end=length;
    int steps=1;
    bool flag_one=1, flag_two=0;
    bool negative_start=0, negative_end=0, negative_steps=0;

    for(int i =0; str.ch_arr[i]!='\0'; i++){

        if((str.ch_arr[i]!=':') && ((str.ch_arr[i] <= '0') || (str.ch_arr[i] >= '9')) && (str.ch_arr[i]!='-')){ // if any other character comes;
            cout<<"Wrong Charcters in slicing "<<endl;
            return String("");
        }
        
        if((str.ch_arr[i] == ':') &&(flag_one==1)){
            flag_one = 0;
            flag_two = 1;
            start = num;
            num=length;
            continue;
        }
        else if((str.ch_arr[i] == ':') &&(flag_two==1)){
            flag_two = 0;
            end = num;
            num=0;
            continue;
        }

        else{
            if(str.ch_arr[i] == '-'){
                if(flag_one){
                    negative_start=1;
                    continue;
                }
                else if(flag_two){
                    negative_end =1;
                    continue;
                }
                else{
                    negative_steps=1;
                    continue;
                }
            }
            
            num == length? num =0: num; // end should be num

            num*=10;
            num+=str.ch_arr[i]-'0';
        }

    }

    if(flag_two){ //if only one colon existed
        end =num;
        steps=1;
    }
    else{ // if 2 colons existed
        num>0? steps=num:steps=1;
    }

    if((start<length) && (end <=length)){
        if((negative_start) && (negative_end)){
            if(start<end){ // these both are postive which is why i am checking start <end
                return String("");
            }
        }
        if(negative_start){
            start = length - start;
        }
        if(negative_end){
            end = length - end;
        }

        
        if(negative_steps){// if steps negative
            if(start == 0){
                start =length;
            }
            if(end == length){
                end= 0;
            }
            
            return helperReturningTheSicingRequired(start, end, -1*steps);
        }
        else{ // if steps positive
            
            return helperReturningTheSicingRequired(start, end, steps);
        }
            
    }


    cout<<"Invalid string"<<endl;

    return String("");

}

String String :: slice(const char * temp){
    // this function will work for all cases except if steps are negative except for steps ==-1;

    // ALL THE  EXPLANATION IS WRITTEN IN THE PREVIOUS SLICE FUNCTION THAT TAKES A String AS A PARAMETER.

    /*start:stop:steps
    this is the genral formula
    if only onne colon then steps are considerd as defaultly one;
    1)start means to start FROM that index e.g 2 means the 3rd postion.
    2)stop means to stop BEFORE that index e.g 4 means to end before 5th postion
    3) steps mean how many steps to move forward after each charachter */

    if(temp[0]== '\0'){
        cout<<"Invalid SLicing"<<endl;
        return String("");
    }

    //checking if there even is a colon in the code
    bool colon_exists= false;
    for(int i =0; temp[i]!='\0';i++){
        if(temp[i]==':'){
            colon_exists=true;
        }
    }

    if(!colon_exists){ // if there is no colon in the slicing
        return String("");
    }



    int num =0;
    int start=0;
    int end=length;
    int steps=1;
    bool flag_one=1, flag_two=0;
    bool negative_start=0, negative_end=0, negative_steps=0;

    for(int i =0; temp[i]!='\0'; i++){

        if((temp[i]!=':') && ((temp[i] <= '0') || (temp[i] >= '9')) && (temp[i]!='-')){ // if any other character comes;
            cout<<"Wrong Charcters in slicing "<<endl;
            return String("");
        }
        
        if((temp[i] == ':') &&(flag_one==1)){
            flag_one = 0;
            flag_two = 1;
            start = num;
            num=length;
            continue;
        }
        else if((temp[i] == ':') &&(flag_two==1)){
            flag_two = 0;
            end = num;
            num=0;
            continue;
        }

        else{
            if(temp[i] == '-'){
                if(flag_one){
                    negative_start=1;
                    continue;
                }
                else if(flag_two){
                    negative_end =1;
                    continue;
                }
                else{
                    negative_steps=1;
                    continue;
                }
            }
            
            num == length? num =0: num; // end should be num

            num*=10;
            num+=temp[i]-'0';
        }

    }

    if(flag_two){ //if only one colon existed
        end =num;
        steps=1;
    }
    else{ // if 2 colons existed
        num>0? steps=num:steps=1;
    }

    if((start<length) && (end <=length)){
        if((negative_start) && (negative_end)){
            if(start<end){ // these both are postive which is why i am checking start <end
                return String("");
            }
        }

        if(negative_start){
            start = length - start;
        }
        if(negative_end){
            end = length - end;
        }

        if(negative_steps){// if steps negative
            if(start == 0){
                start =length;
            }
            if(end == length){
                end= 0;
            }

            return helperReturningTheSicingRequired(start, end, -1*steps);
        }
        else{ // if steps positive
            
            return helperReturningTheSicingRequired(start, end, steps);
        }
    }


    cout<<"Invalid string"<<endl;
    return String("");

}
//--------------------------------------------------------------------------------------------------------
//------------------------------------------->Styling Functions<------------------------------------------
//--------------------------------------------------------------------------------------------------------

String String :: lower(){

    String temp(ch_arr);

    for(int i=0; i<length; i++){
        if((temp.ch_arr[i] >='A') && (temp.ch_arr[i]<='Z')){
            temp.ch_arr[i] += 32;
        }
    }

    return temp;
}

String String ::upper(){

    String temp(ch_arr);

    for(int i=0; i<length; i++){
        if((temp.ch_arr[i] >='a') && (temp.ch_arr[i]<='z')){
            temp.ch_arr[i] -= 32;
        }
    }

    return temp;
}

String String :: title(){

    String temp(ch_arr);
    
    for(int i=0; i<length; i++){

        if(i == 0){
            if((temp.ch_arr[i] >='a') && (temp.ch_arr[i]<='z')){
                temp.ch_arr[i] -= 32;
            }
        }

        /*the below condition checks if any index has a something different than a character, if it is 
        different then the next index is checked. if next index has character it is made bigger;*/
        else if((temp.ch_arr[i] <='A') || (temp.ch_arr[i]>='z') || ((temp.ch_arr[i]>=91) && (temp.ch_arr[i]<=96))){

            if((temp.ch_arr[i+1] >='a') && (temp.ch_arr[i+1]<='z')){
                temp.ch_arr[i+1] -= 32;
            }
        }

        //below checks for if captal leters come in middle of words; 
        else{
            if((temp.ch_arr[i+1] >='A') && (temp.ch_arr[i+1]<='Z')){
                temp.ch_arr[i+1] += 32;
            }
        }

    }

    return temp;

}

String String :: swapcase(){

    String temp(ch_arr);

    for(int i=0; i<length; i++){
        if((temp.ch_arr[i] >='A') && (temp.ch_arr[i]<='Z')){
            temp.ch_arr[i] += 32;
        }

        else if((temp.ch_arr[i] >='a') && (temp.ch_arr[i]<='z')){
            temp.ch_arr[i] -= 32;
        }
    }


    return temp;

}

//--------------------------------------------------------------------------------------------------------
//---------------------------------------------->Starts With<---------------------------------------------
//--------------------------------------------------------------------------------------------------------

bool String :: startsWith(String& str){

    bool flag=1;

    for(int i =0; str.ch_arr[i]!= '\0'; i++){

        if(ch_arr[i] != str.ch_arr[i]){
            flag =0;
            break;
        }

    }

    return flag;
}
bool String :: startsWith(const char* temp){

    bool flag=1;

    for(int i =0; temp[i]!= '\0'; i++){

        if(ch_arr[i] != temp[i]){
            flag =0;
            break;
        }

    }

    return flag;
}

//--------------------------------------------------------------------------------------------------------
//----------------------------------------------->Ends With<----------------------------------------------
//--------------------------------------------------------------------------------------------------------

bool String :: endsWith(String& str){

    bool flag=1;

    int index=0;
    for(int i = length-str.length; ch_arr[i]!='\0';i++){

        if(ch_arr[i] != str.ch_arr[index]){
            flag =0;
            break;
        }
        index++;
    }

    return flag;

}
bool String :: endsWith(const char* temp){

    int temp_length=0;
    for(int i =0; temp[i]!='\0'; i++){
        temp_length++;
    }

    bool flag=1;

    int index =0;
    for(int i = length-temp_length; ch_arr[i]!='\0';i++){

        if(ch_arr[i] != temp[index]){
            flag =0;
            break;
        }
        index++;
    }

    return flag;
}

//--------------------------------------------------------------------------------------------------------
//----------------------------------------------->JOIN functions<----------------------------------------------
//--------------------------------------------------------------------------------------------------------

String String :: join(String& str){

    String new_str_to_return(ch_arr);

    if (length == 0){ // Edge case: empty string
        return String("");
    } 
    if (str.length == 0){// Edge case: empty separator
        return *this; 
    }

    int new_length = length + str.length * length - str.length; // total size should be original size + number of char in str multiplied by number of charachters - number of char. as it is one less
    char * ptr = new char[new_length +1]; // +1 for null


    int index=0; 
    for(int i =0; i<new_length; i++){

        if(i != 0){

            for(int j =0; j<str.length; j++){
                ptr[i] = str.ch_arr[j];
                i++;
            }
        }
        
        ptr[i] = new_str_to_return.ch_arr[index];
        index++;
    }

    ptr[new_length]='\0';

    new_str_to_return.length = new_length;

    delete [] new_str_to_return.ch_arr;
    new_str_to_return.ch_arr = ptr;


    return new_str_to_return; 
}
String String :: join(const char * temp){

    String new_str_to_return(ch_arr);

    if (new_str_to_return.length == 0){ // Edge case: empty string
        return String("");
    } 
    

    int temp_length=0;
    for(int i =0; temp[i]!='\0'; i++){
        temp_length++;
    }

    if (temp_length == 0){// Edge case: empty separator
        return *this; 
    }

    int new_length = length + temp_length * length - temp_length;
    char * ptr = new char[new_length +1]; // +1 for null


    int index=0; 
    for(int i =0; i<new_length; i++){

        if(i != 0){

            for(int j =0; j<temp_length; j++){
                ptr[i] = temp[j];
                i++;
            }
        }
        
        ptr[i] = new_str_to_return.ch_arr[index];
        index++;
    }

    ptr[new_length]='\0';

    new_str_to_return.length = new_length;

    delete [] new_str_to_return.ch_arr;
    new_str_to_return.ch_arr = ptr;

    return new_str_to_return;

}
String String :: join(char * temp){
    String new_str_to_return(ch_arr);

    if (new_str_to_return.length == 0){ // Edge case: empty string
        return String("");
    } 
    

    int temp_length=0;
    for(int i =0; temp[i]!='\0'; i++){
        temp_length++;
    }

    if (temp_length == 0){// Edge case: empty separator
        return *this; 
    }

    int new_length = length + temp_length * length - temp_length;
    char * ptr = new char[new_length +1]; // +1 for null


    int index=0; 
    for(int i =0; i<new_length; i++){

        if(i != 0){

            for(int j =0; j<temp_length; j++){
                ptr[i] = temp[j];
                i++;
            }
        }
        
        ptr[i] = new_str_to_return.ch_arr[index];
        index++;
    }

    ptr[new_length]='\0';

    new_str_to_return.length = new_length;

    delete [] new_str_to_return.ch_arr;
    new_str_to_return.ch_arr = ptr;

    return new_str_to_return;
}

//--------------------------------------------------------------------------------------------------------
//----------------------------------------------->JOIN functions<----------------------------------------------
//--------------------------------------------------------------------------------------------------------

String String :: replace(String& orignal, String& str_replace){

    if(str_replace.length == 0){ // if the replace string is empty it means that we need to remove the orginal 
        String temp = (*this).remove("aba");
        (*this) = temp;
        return String (*this);
    }

    char *ptr =nullptr;
    int new_length =0;

    for(int i =0; i<length; i++){

        
        bool flag = true;

        for(int j =0; j<orignal.length; j++){
            if(ch_arr[i+j]!=orignal.ch_arr[j]){
                flag = false;
                break;
            }
        }

        if(flag){
            
            if(str_replace.length == orignal.length){ // handling same length
                for(int j=0; j<str_replace.length; j++){
                    ch_arr[i+j] = str_replace.ch_arr[j];
                }

            }

            else{ // handling different length
                new_length = length + str_replace.length - orignal.length;
                ptr = new char[new_length+1];

                int index=0;
                for(int j=0; j<new_length;){

                    if(i==j){
                        for(int k =0; k<str_replace.length; k++){
                            ptr[j] = str_replace.ch_arr[k];
                            j++;
                        }
                        index+=orignal.length; // to move the index to correct postion after the new substring added
                    }

                    else{
                        ptr[j] = ch_arr[index];
                        index++;
                        j++;
                    }
                    
                }

                length = new_length;
                ptr[new_length] = '\0';
                delete [] ch_arr;
                ch_arr = ptr;

            }
        }

    }


    return String (*this);
}
String String :: replace(const char *original, const char *str_replace){

    String org(original);
    String replace(str_replace);

    String temp = (*this).replace(org, replace);
    (*this) = temp;

    return String(*this);
}

//--------------------------------------------------------------------------------------------------------
//----------------------------------------------->SPLIT functions<----------------------------------------------
//--------------------------------------------------------------------------------------------------------

String* String :: split(String& str, int &size){

    int index_arr[100]= {0};
    int index_arr_count=0;
    for(int i=0 ;i<length ;i++){

        bool isSame=1;
        for(int j =0; j<str.length; j++){
            if(ch_arr[i+j] != str.ch_arr[j]){
                isSame=0;
                break;
            }
        }

        if(isSame){
            index_arr[index_arr_count] = i;
            index_arr_count++;
        }

    }


   
    size = index_arr_count + 1; // + 1 as for exaple slice a banana two times and you get 3 pieces
    String* ptr_array = new String[size]; 

    
    int prev_index = 0;
    for (int i = 0; i < index_arr_count; i++) {
        int start_index = prev_index;
        int end_index = index_arr[i];

        String sliced = helperReturningTheSicingRequired(start_index, end_index);
        ptr_array[i]= sliced;
        
        prev_index = index_arr[i] + str.length; // addition of length as the we need to move past the charachters which are the splitters. they need to be removed 

    }

    String sliced = helperReturningTheSicingRequired(prev_index, length);
    ptr_array[index_arr_count] = sliced;

    return ptr_array;
}

String* String :: split(const char *temp, int &size){

    String str = temp;

    return split(str, size);

}
String* String :: split(char *temp, int &size){
    String str = temp;

    return split(str, size);
}

//--------------------------------------------------------------------------------------------------------
//---------------------------------------------->Destructors<---------------------------------------------
//--------------------------------------------------------------------------------------------------------
String::~String() {
    delete[] ch_arr;
}


// int main(){



//     String s("ababab");
//     String org ("aba");
//     String remover ("3");
//     String removed = s.replace("aba", "34");
//     removed.display();
        
// return 0;
// }


