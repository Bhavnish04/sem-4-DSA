#include<iostream>
#include<string>
#define max 10
using namespace std;

class hashvalues{
    public:

    long int number;
    hashvalues *next;
};
class hashtable{
    hashvalues *data[max];
    int index;
    public:
    void initialize(){
        for(int i=0;i<max;i++){
            data[i]=NULL;
        }
    }
    hashvalues *createnode(int value)
    {
        hashvalues *temp = new hashvalues;
        temp->next = NULL;
        temp->number = value;
        return temp;
    }
    int hashfunction(int v){
        return v%max;

    }
    void insertval(int k){
        int index = hashfunction(k);
        hashvalues *temp = new hashvalues;
        hashvalues *head = new hashvalues;
        head = createnode(k);
        temp = data[index];
        if (temp == NULL)
        {
            data[index] = head;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
    }
    void display(){
        for(int i=0;i<max;i++){
            cout<<i<<"]";
            hashvalues *temp=new hashvalues;
            temp=data[i];
            while(temp!=NULL){
                cout<<temp->number<<"-->";
                temp=temp->next;
            }
            cout<<"\n";
        }
    }
    void search(int item){
        int index = hashfunction(item);
        hashvalues *ptr=NULL;
        ptr=data[index];
        if(ptr==NULL){
            cout<<"Element not present";
        }
        else{
            int flag=0;
            while(ptr!=NULL){
                if(ptr->number==item){
                    cout<<"Yes present in the hashtable";
                    flag++;
                }
                ptr=ptr->next;
            }
            if(flag==0){
                cout<<"Element is not present";
            }

        }
        
        
    }

};
int main(){
    long int num,c;
    hashtable a;
    a.initialize();
    do
    {
        cout << "\n1.Insert \n2.Display\n3.Search\n4.Exit" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter a number :";
            cin >>num;
            a.insertval(num);
            break;
        case 2:
            a.display();
            break;
        case 3:int k;
            cout<<"Enter the number to be searched ";
            cin>>k;
            a.search(k);
        }
        

    } while (c != 4);
    
    
    
    return 0;
}
