#include<iostream>
#include<vector>
#include <string>

using namespace std;
 

class subject {

public:

    string code;
    string name;
    int credit;
    int avb;
    string prof;
    string vanue;

    int core;
    vector<subject> elective;
    int on=0;
    
    subject() : code("   "), name(""), credit(0), prof("  "), vanue("    "),  core(0) {}
    subject(string code, string name, int credit , int core, string prof,string vanue)
    {
        this->code=code;
        this->name=name;
        this->credit=credit;
        this->avb=credit;
        this->core=core;
        this->on=1;
        this->prof=prof;
        this->vanue=vanue;
    }
    
};

subject tableatumn[22][5][5]; 
vector<vector<subject>> sub;


void dataasignatumn();
void freeslotassign();
vector<subject> weeklecvec(int n);
bool isprofavailable(string faculty,int i,int j, int k);
bool isvanueavailable(string,int ,int, int);
bool islecreq(int i,int j,int k);
bool islectogather(string code,string faculty,string vanue,int i,int j,int k);
void displaytableindividual(int i);
bool iselelecavailable(string faculty,string vanue,int i,int j,int k);

void dataassignatumn(){

    

}
int totall;
vector<subject> weeklecvec(int n){
    
    totall = 0;
    for(int i=0;i<sub[n].size();++i){
        totall+=sub[n][i].credit;
    }

    vector<subject> weeklec;
    weeklec.resize(0);
    //weeklec.clear();

    int k=0;

    for(int i=0;i<=totall;++i){
    
        if(sub[n][k].avb){
        
           weeklec.push_back(sub[n][k]);
           sub[n][k].avb--;
           
        }
        k++;
        if(k==sub[n].size()){
            k=0;
            }
    }
    
    return weeklec;
}

bool isprofavailable(string faculty,int i,int j,int k){

    
        
        int p=j;
        for (;j>=0;--j){
        
            if(faculty == tableatumn[i][j][k].prof)
            return false;
        
        }
    

    

        for(int i=0;i<sub.size();++i){
            if(faculty==tableatumn[i][j][k].prof)
            return false;
        }
    
        return true;
}

bool isvanueavailable(string vanue,int i,int j, int k){

    for(int i=0;i<sub.size();++i ){
        if(vanue==tableatumn[i][j][k].vanue)
        return false;
    }

    return true;
}

bool islecreq(int i,int j,int k){

    int max=0;
    for(int i=0;i<5;++i){
        max+=tableatumn[i][j][k].on;
    }

    if(max>4)
    return false;
    else
    return true;
}

bool iselelecavailable(string faculty,string vanue,int i,int j,int k){
    
    
    for(int a=0;a<tableatumn[i][j][k].elective.size();++a){

        if(faculty==tableatumn[i][j][k].elective[a].prof)
        return false;

        if(vanue==tableatumn[i][j][k].elective[a].vanue)
        return false;
        
    }

    return true;
}

vector<subject> weeklec;
void freeslotassign(int i){
    
   
   weeklec = weeklecvec(i);
   
   int check=0;
   int t=0;
   
   for(int j=0;j<5;++j){
       
       for(int k=0;k<5;++k){
       
           if(isprofavailable(weeklec[t].prof,i,j,k)&&isvanueavailable(weeklec[t].vanue,i,j,k) 
                && (weeklec[t].core==0)  ||  islectogather(weeklec[t].code,weeklec[t].prof,weeklec[t].vanue,i,j,k)){
               
               if(t<=weeklec.size()){
                   tableatumn[i][j][k]= weeklec[t];
                   t++;
                   continue ;
               }
               
           }
           if(weeklec[t].core!=0 ){
               
               if(iselelecavailable(weeklec[t].prof,weeklec[t].vanue,i,j,k)){
               
               tableatumn[i][j][k].elective.push_back(weeklec[t]);
               t++;
               
               continue ;
               
           }
           
               
           }
           
       }
       
   }
   
}

            
           


bool islectogather(string code,string faculty,string vanue,int i,int j,int k){

    for(int i=0;i<sub.size();++i){
        if(code==tableatumn[i][j][k].code&&faculty==tableatumn[i][j][k].prof&&vanue==tableatumn[i][j][k].vanue){
        return true;
        }
    }
    
        return false;
}

void displaytableindividual(int i){
void displaytableindividual(int i){

    string day[6]={"       "," ||      Mon      || ","      Tue      || ","       Wen      || ","       Thu       || ","       Fri      || "};
    string time[5]={"8 to 9 || ","9 to 10 || ","10 to 11 || ","11 to 12 || ","12 to 1 || "};
    
    for(int j=0;j<6;++j){
        cout<< day[j]<<"";
    }
    cout<<endl;
    cout<<"\n-------------------------------------------------------------------------------------"<<endl;
    for(int j=0;j<5;++j){

        cout<<time[j];
        for(int k=0;k<5;k++){

            if(tableatumn[i][j][k].core==0){
                cout<<tableatumn[i][j][k].code<<","<<tableatumn[i][j][k].prof<<","<<tableatumn[i][j][k].vanue<<" || ";
            }
            if(tableatumn[i][j][k].core){
                    
                for(int s=0;s<tableatumn[i][j][k].elective.size();++s){

                    cout<<tableatumn[i][j][k].elective[s].code<<","<<tableatumn[i][j][k].elective[s].prof<<","<<tableatumn[i][j][k].elective[s].vanue<<" || "<<endl;

                }

            }
            
        }

        cout<<"\n"<<"-------------------------------------------------------------------------------------"<<endl;

    }
    
    

}


int main(){
    int c;
    cout<<"which time for you want to generate ? \n"
    "1 for autumn\n"
    "2 for winter\n";
    
    cin>>c;
    
    if(c==1){
    
        
    sub.resize(22);


//----------------------------0. Data for btech ict sem I sec a --------------------------------------------//

    
    subject sub00("SC107","Calculus",3,0,"MKG","LT2"),
    sub01("EL111","Basic Electronic Circuits",3,0,"SM","LT2"),
    sub02("IT112","Introduction to Programming",3,0,"BG","LT2"),
    sub03("PC110","Language and Literature",3,0,"Amishal Modi","LT2"), 
    sub04("IC101","Introduction to ICT",1,0,"AKR","LT2");
    
    sub[0].push_back(sub00);
    sub[0].push_back(sub01);
    sub[0].push_back(sub02);
    sub[0].push_back(sub03);
    sub[0].push_back(sub04);
    
//----------------------------1. Data for btech ICT sem I sec b --------------------------------------------//

    subject sub10("SC107","Calculus",3,0,"SB2","LT3"),
    sub11("EL111","Basic Electronic Circuits",3,0,"RLD","LT3"),
    sub12("IT112","Introduction to Programming",3,0,"MK","LT3"),
    sub13("PC110","Language and Literature",3,0,"Amishal Modi","LT3"), 
    sub14("IC101","Introduction to ICT",1,0,"GV","LT3");

    sub[1].push_back(sub10);
    sub[1].push_back(sub11);
    sub[1].push_back(sub12);
    sub[1].push_back(sub13);
    sub[1].push_back(sub14);
    
 //----------------------------2. Data for btech EVD sem I --------------------------------------------//  

    subject sub20("IT112","Introduction to Programming",3,0,"MK","LT3"),
    sub21("PC110","Language and Literature",3,0,"Amishal Modi","LT3"),
    sub22("ED111","Engineering Mathematics I",3,0,"PK2","CEP212"),
    sub23("EL111","Basic Electronic Circuits",3,0,"SM","LT3"),
    sub24("ED112","Engineering Physics",3,0,"AG","CEP212");

    sub[2].push_back(sub20);
    sub[2].push_back(sub21);
    sub[2].push_back(sub22);
    sub[2].push_back(sub23);
    sub[2].push_back(sub24);

//----------------------------3. Data for btech MnC sem I --------------------------------------------// 

    subject sub30("PC110","Language and Literature",3,0,"Amishal Modi","LT3"),
    sub31("MC111","Mathematical, Algorithmic, and Computational Thinking",3,0,"VS","CEP205"),
    sub32("MC112","Computer Organization and Programming",3,0,"RP","CEP206"),
    sub33("MC123","Discrete Mathematics",3,0,"SP","CEP205"),
    sub34("MC116","Digital Logic Design",1,0,"SR","CEP206");

    sub[3].push_back(sub30);
    sub[3].push_back(sub31);
    sub[3].push_back(sub32);
    sub[3].push_back(sub33);
    sub[3].push_back(sub34);

//----------------------------4. Data for btech Ict sem III sec a--------------------------------------------// 

    subject sub40("HM216","Science ,Technology, and Society",3,0,"SJ","LT1"),
    sub41("CT204","Signals and Systems ",3,0,"HP","LT2"),
    sub42("IT216","Design and Analysis of Algorithms",3,0,"PB","LT1"),
    sub43("IT227","Computer Systems Programming",3,0,"AKM","LT2"),
    sub44("SC223","Linear Algebra",3,0,"AT","LT1");

    sub[4].push_back(sub40);
    sub[4].push_back(sub41);
    sub[4].push_back(sub42);
    sub[4].push_back(sub43);
    sub[4].push_back(sub44);

//----------------------------5. Data for btech Ict sem III sec b--------------------------------------------// 

    subject sub50("HM216","Science ,Technology, and Society",3,0,"SJ","LT2"),
    sub51("CT204","Signals and Systems ",3,0,"PK","LT3"),
    sub52("IT216","Design and Analysis of Algorithms",3,0,"SP","LT2"),
    sub53("IT227","Computer Systems Programming",3,0,"SB","LT3"),
    sub54("SC223","Linear Algebra",3,0,"RM","LT2");

    sub[5].push_back(sub50);
    sub[5].push_back(sub51);
    sub[5].push_back(sub52);
    sub[5].push_back(sub53);
    sub[5].push_back(sub54);

//----------------------------6. Data for btech mnc sem III--------------------------------------------// 

    subject sub60("HM216","Science, Technology, and Society",3,0,"SJ","LT2"),
    sub61("MC211","Functions of Several Variables and PDEs" ,3,0,"MS","CEP205"),
    sub62("MC212","Database Management Systems",3,0,"RC","CEP206"),
    sub63("MC213","Design and Analysis of Algorithms",3,0,"AT2","CEP205"),
    sub64("MC214","Operating Systems (along with IE411)",3,0,"SS","CEP206"),
    sub65("MC216","Probability and Random Processes",3,0,"SK","CEP205");

    sub[6].push_back(sub60);
    sub[6].push_back(sub61);
    sub[6].push_back(sub62);
    sub[6].push_back(sub63);
    sub[6].push_back(sub64);
    sub[6].push_back(sub65);

//----------------------------7. Data for btech ict sem V--------------------------------------------// 

    subject sub70("IT314","Software Engineering",3,0,"ST","LT3"),
    sub71("IT304","Computer Networks",3,0,"PKS","LT3"),
    sub72("CT303","Digital Communication",3,0,"AJ","LT3"),
    sub73("IE402","Optimization",3,4,"MK2","CEP203"),
    sub74("IE411","Operating system",3,4,"SS","CEP211"),
    sub75("IE406","Machine Learning",3,4,"MVJ","CEP110"),
    sub76("IE408","Control of Autonomous Systems",3,4,"RLD","CEP110"),
    sub77("IE407","Internet of Things",3,1,"VSP","CEP205"),
    sub78("HN000","Honours course ",3,1,"F88","CEP211");

    sub[7].push_back(sub70);
    sub[7].push_back(sub71);
    sub[7].push_back(sub72);
    sub[7].push_back(sub73);
    sub[7].push_back(sub74);
    sub[7].push_back(sub75);
    sub[7].push_back(sub76);
    sub[7].push_back(sub77);
    sub[7].push_back(sub78);
    
//----------------------------8. Data for btech ictCS sem V--------------------------------------------// 

    subject  sub80("IE402","Optimization",3,4,"MK2","CEP203"),
    sub81("IE411","Operating system",3,4,"SS","CEP211"),
    sub82("IE406","Machine Learning",3,4,"MVj","CEP110"),
    sub83("IT314","Software Engineering",3,0,"ST","LT3"),
    sub84("IT304","Computer Networks",3,0,"PKS","LT3"),
    sub85("CT303","Digital Communication",3,0,"AJ","LT3"),
    sub86("IE408","Control of Autonomous Systems",3,4,"RLD","CEP110"),
    sub87("IE407","Internet of Things",3,1,"VSP","CEP205"),
    sub88("HN000","Honours course ",3,1,"F88","CEP211"),
    sub89("CS374","Computational and Numerical Methods",3,0,"MKR","LT1");

    sub[8].push_back(sub80);
    sub[8].push_back(sub81);
    sub[8].push_back(sub82);
    sub[8].push_back(sub83);
    sub[8].push_back(sub84);
    sub[8].push_back(sub85);
    sub[8].push_back(sub86);
    sub[8].push_back(sub87);
    sub[8].push_back(sub88);
    sub[8].push_back(sub89); 

//----------------------------9. Data for btech Mnc sem V--------------------------------------------//   

    subject sub90("MC311","Mathematical Optimization",3,0,"NKS","CEP205"),
    sub91("MC312","Modelling and Simulation",3,0,"MT","CEP206"),
    sub92("MC313","Algebraic Structures",3,0,"PK2","CEP205"),
    sub93("MC314","Principles of Economics",3,0,"Gaurav Singh","CEP205");

    sub[9].push_back(sub90);
    sub[9].push_back(sub91);
    sub[9].push_back(sub92);
    sub[9].push_back(sub93);

//----------------------------10. Data for btech ICT + CS sem VII--------------------------------------------//   

    subject sub100("CT425","RF and Antenna Engineering",3,4,"DKG","CEP003"),
    sub101("CT546","Introduction to Wireless Communication",3,4,"AJ","CEP104"),
    sub102("CT505","Detection and Estimation Theory",3,4,"SM","CEP105"),
    sub103("CT437","Speech Communication",3,4,"HP","CEP107"),
    sub104("EL453","Nanoelectronics",3,7,"RP","CEP109"),
    sub105("EL467","Digital Programming",3,7,"YA","CEP202"),
    sub106("EL524","Basics of VLSI",3,7,"DNC","CEP203"),
    sub107("EL526","VLSI System Design",3,7,"YA","CEP205"),
    sub108("EL530","Introduction to Embedded Artificial Intelligence",3,20,"TKM","CEP206"),
    sub109("EL312","Solid State Devices",3,7,"AKR","CEP003"),
    sub1010("EL531","Digital IC Design",3,7,"BM","CEP104"),
    sub1011("IT414","Software Project Management",3,9,"JP","CEP105"),
    sub1012("IT495","DNA Storage and Security",3,9,"MKG","CEP107"),
    sub1013("IT486","Blockchains and Cryptocurrencies",3,9,"AMM","CEP109"),
    sub1014("IT550","Information Retrieval",3,9,"Sandip Modha","CEP202"),
    sub1015("IT499","Biometric Security",3,9,"SB","CEP203"),
    sub1016("IT494","Big Data Processing",3,9,"PMJ","CEP205"),
    sub1017("IT498","Query Processing",3,9,"MB","CEP206"),
    sub1018("IT496","Introduction to Data Mining",3,9,"AR2","CEP003"),
    sub1019("IT555","Deep Neural NLP & Applications",3,9,"SDG","CEP104"),
    sub1020("HM484","Modern European Philosophy",3,6,"BK","CEP105"),
    sub1021("HM333","Human Behaviour Management",3,6,"N Banerjee","CEP107"),
    sub1022("HM490","Communicating Conservation: Role of Cinema in influencing global environmental consciousness",2,6,"Anirban Duttagupta","CEP109"),
    sub1023("HM403","Corporate Finance",3,6,"Cyril Jos","CEP202"),
    sub1024("HM491","Crime Fiction",3,6,"Nandini Saha","CEP203"),
    sub1025("HM492","Design Thinking",2,6,"GV","CEP205"),
    sub1026("SC435","Introduction to Complex Network",3,5,"MT","CEP206"),
    sub1027("SC471","Algorithmic Graph Theory",3,5,"VS","CEP003"),
    sub1028("SC401","Introduction Nonlinear Dynamics",3,5,"AR","CEP210"),
    sub1029("SC421","Introduction to Modern Algebra",3,5,"SB2","CEP212"),
    sub1030("SC477","Quantum Information Theory",3,5,"GD","CEP210");


    sub[10].push_back(sub100);
    sub[10].push_back(sub101);
    sub[10].push_back(sub102);
    sub[10].push_back(sub103);
    sub[10].push_back(sub104);
    sub[10].push_back(sub105);
    sub[10].push_back(sub106);
    sub[10].push_back(sub107);
    sub[10].push_back(sub108);
    sub[10].push_back(sub109);
    sub[10].push_back(sub1010);
    sub[10].push_back(sub1011);
    sub[10].push_back(sub1012);
    sub[10].push_back(sub1013);
    sub[10].push_back(sub1014);
    sub[10].push_back(sub1015);
    sub[10].push_back(sub1016);
    sub[10].push_back(sub1017);
    sub[10].push_back(sub1018);
    sub[10].push_back(sub1019);
    sub[10].push_back(sub1020);
    sub[10].push_back(sub1021);
    sub[10].push_back(sub1022);
    sub[10].push_back(sub1023);
    sub[10].push_back(sub1024);
    sub[10].push_back(sub1025);
    sub[10].push_back(sub1026);
    sub[10].push_back(sub1027);
    sub[10].push_back(sub1028);
    sub[10].push_back(sub1029);
    sub[10].push_back(sub1030);

//----------------------------11. Data for btech ICT CS only sem VII--------------------------------------------// 

    subject sub110("IT555","Deep Neural NLP & Applications",3,2,"SDG","CEP110"),
    sub111("IT494","Big Data Processing",3,2,"PMJ","CEP211"),
    sub112("CT425","RF and Antenna Engineering",3,4,"DKG","CEP003"),
    sub113("CT546","Introduction to Wireless Communication",3,4,"AJ","CEP104"),
    sub114("CT505","Detection and Estimation Theory",3,4,"SM","CEP105"),
    sub115("1CT437","Speech Communication",3,4,"HP","CEP107"),
    sub116("EL453","Nanoelectronics",3,7,"RP","CEP109"),
    sub117("EL467","Digital Programming",3,7,"YA","CEP202"),
    sub118("EL524","Basics of VLSI",3,7,"DNC","CEP203"),
    sub119("EL526","VLSI System Design",3,7,"YA","CEP205"),
    sub1110("EL530","Introduction to Embedded Artificial Intelligence",3,20,"TKM","CEP206"),
    sub1111("EL312","Solid State Devices",3,7,"AKR","CEP003"),
    sub1112("EL531","Digital IC Design",3,7,"BM","CEP104"),
    sub1113("IT414","Software Project Management",3,9,"JP","CEP105"),
    sub1114("IT495","DNA Storage and Security",3,9,"MKG","CEP107"),
    sub1115("IT486","Blockchains and Cryptocurrencies",3,9,"AMM","CEP109"),
    sub1116("IT550","Information Retrieval",3,9,"Sandip Modha","CEP202"),
    sub1117("IT499","Biometric Security",3,9,"SB","CEP203"),
    sub1118("IT494","Big Data Processing",3,9,"PMJ","CEP205"),
    sub1119("IT498","Query Processing",3,9,"MB","CEP206"),
    sub1120("IT496","Introduction to Data Mining",3,9,"AR2","CEP003"),
    sub1121("IT555","Deep Neural NLP & Applications",3,9,"SDG","CEP104"),
    sub1122("HM484","Modern European Philosophy",3,6,"BK","CEP105"),
    sub1123("HM333","Human Behaviour Management",3,6,"N Banerjee","CEP107"),
    sub1124("HM490","Communicating Conservation: Role of Cinema in influencing global environmental consciousness",2,6,"Anirban Duttagupta","CEP109"),
    sub1125("HM403","Corporate Finance",3,6,"Cyril Jos","CEP202"),
    sub1126("HM491","Crime Fiction",3,6,"Nandini Saha","CEP203"),
    sub1127("HM492","Design Thinking",2,6,"GV","CEP205"),
    sub1128("SC435","Introduction to Complex Network",3,5,"MT","CEP206"),
    sub1129("SC471","Algorithmic Graph Theory",3,5,"VS","CEP003"),
    sub1130("SC401","Introduction Nonlinear Dynamics",3,5,"AR","CEP210"),
    sub1131("SC421","Introduction to Modern Algebra",3,5,"SB2","CEP212"),
    sub1132("SC477","Quantum Information Theory",3,5,"GD","CEP210");


    sub[11].push_back(sub110);
    sub[11].push_back(sub111);
    sub[11].push_back(sub112);
    sub[11].push_back(sub113);
    sub[11].push_back(sub114);
    sub[11].push_back(sub115);
    sub[11].push_back(sub116);
    sub[11].push_back(sub117);
    sub[11].push_back(sub118);
    sub[11].push_back(sub119);
    sub[11].push_back(sub1110);
    sub[11].push_back(sub1111);
    sub[11].push_back(sub1112);
    sub[11].push_back(sub1113);
    sub[11].push_back(sub1114);
    sub[11].push_back(sub1115);
    sub[11].push_back(sub1116);
    sub[11].push_back(sub1117);
    sub[11].push_back(sub1118);
    sub[11].push_back(sub1119);
    sub[11].push_back(sub1120);
    sub[11].push_back(sub1121);
    sub[11].push_back(sub1122);
    sub[11].push_back(sub1123);
    sub[11].push_back(sub1124);
    sub[11].push_back(sub1125);
    sub[11].push_back(sub1126);
    sub[11].push_back(sub1127);
    sub[11].push_back(sub1128);
    sub[11].push_back(sub1129);
    sub[11].push_back(sub1130);
    sub[11].push_back(sub1131);
    sub[11].push_back(sub1132);

//----------------------------12. Data for mtech ICT sem I--------------------------------------------//   

    subject sub120("PC503","Programming Lab",1,0,"RM2","CEP003"),
    sub121("PC512","Communication Skills and Technical Writing",2,0,"AG","CEP104"),
    sub122("IT580","Advanced Algorithm",3,0,"AT2","CEP105"),
    sub123("IT582","Foundations of Machine Learning",3,0,"PA","CEP205"),
    sub124("EL526","VLSI System Design",3,0,"YA","CEP206"),
    sub125("SC531","Probability and Random Variables",3,12,"NDJ","CEP212"),
    sub126("SC470","Algorithmic Graph Theory",3,12,"VS","CEP210"),
    sub127("IE402","Optimization",3,12,"MK2","CEP109"),
    sub128("SC421","Linear Algebra/Modern Algebra",3,12,"AT/SB2","CEP107"),
    sub129("IE411","Operating Systems",3,12,"SS","CEP105"),
    sub1210("IE406","Machine Learning",3,12,"MVJ","CEP104"),
    sub1211("IT496","Introduction to Data Mining",3,12,"AR2","CEP212"),
    sub1212("IT495","DNA Storage and Security",3,12,"MKG","CEP210"),
    sub1213("EL524","Basics of VLSI",3,12,"DNC","CEP109"),
    sub1214("EL467","Digital Programming",3,12,"YA","CEP107"),
    sub1215("CT505","Detection and Estimation Theory",3,12,"SM","CEP105"),
    sub1216("IE407","Internet of Things",3,12,"VSP","CEP104");

    sub[12].push_back(sub120);
    sub[12].push_back(sub121);
    sub[12].push_back(sub122);
    sub[12].push_back(sub123);
    sub[12].push_back(sub124);
    sub[12].push_back(sub125);
    sub[12].push_back(sub126);
    sub[12].push_back(sub127);
    sub[12].push_back(sub128);
    sub[12].push_back(sub129);
    sub[12].push_back(sub1210);
    sub[12].push_back(sub1211);
    sub[12].push_back(sub1212);
    sub[12].push_back(sub1213);
    sub[12].push_back(sub1214);
    sub[12].push_back(sub1215);
    sub[12].push_back(sub1216);

//----------------------------13. Data for mtech EC sem I--------------------------------------------//   

    subject sub130("PC503","Programming Lab",1,0,"RM2","CEP003"),
    sub131("PC512","Communication Skills and Technical Writing",2,0,"AG","CEP104"),
    sub132("CT546","Introduction to Wireless Communication",3,0,"AJ","CEP105");

    sub[13].push_back(sub130);
    sub[13].push_back(sub131);
    sub[13].push_back(sub132);

//----------------------------14. Data for mtech ICT sem III--------------------------------------------//   

    subject sub140("IT486","Blockchain and Cryptocurrencies",3,4,"AMM","CEP210"),
    sub141("IT531","Advanced Computer Networks",3,4,"SS","CEP212"),
    sub142("IT489","DNA Storage and Security",3,4,"MKG","CEP107"),
    sub143("IT494","Big Data Processing",3,4,"PMJ","CEP109"),
    sub144("IT524","Computer Vision",3,4,"MVJ","CEP003"),
    sub145("IT555","Deep Neural NLP & Applications",3,4,"SDG","CEP210"),
    sub146("IT550","Information Retrieval",3,4,"Sandip Modha","CEP212"),
    sub147("IT499","Biometric Security",3,4,"SB","CEP107"),
    sub148("EL519","Lowpower VLSI Design",2,4,"BM","CEP109"),
    sub149("EL530","Introduction to Embedded Artificial Intelligence",3,4,"TKM","CEP003"),
    sub1410("EL531","Digital IC Design",3,4,"BM","CEP210"),
    sub1411("EL453","Nanoelectronics",3,4,"RP","CEP212");

    sub[14].push_back(sub140);
    sub[14].push_back(sub141);
    sub[14].push_back(sub142);
    sub[14].push_back(sub143);
    sub[14].push_back(sub144);
    sub[14].push_back(sub145);
    sub[14].push_back(sub146);
    sub[14].push_back(sub147);
    sub[14].push_back(sub148);
    sub[14].push_back(sub149);
    sub[14].push_back(sub1410);
    sub[14].push_back(sub1411);

//----------------------------15. Data for btech mnc sem VII--------------------------------------------//

    subject sub150("IT495","DNA Storage and Security",3,4,"MKG","CEP104"),
    sub151("IT486","Blockchains and Cryptocurrencies",3,4,"AMM","CEP105"),
    sub152("IT496","Introduction to Data Mining",3,4,"AR2","CEP107"),
    sub153("IT555","Deep Neural NLP & Applications",3,4,"SDG","CEP109"),
    sub154("SC435","Introduction to Complex Network",3,4,"MT","CEP003"),
    sub155("SC471","Algorithmic Graph Theory",3,4,"VS","CEP104"),
    sub156("SC401","Introduction Nonlinear Dynamics",3,4,"AR","CEP105"),
    sub157("SC477","Quantum Information Theory",3,4,"GD","CEP107"),
    sub158("HM492","Design Thinking",2,1,"GV","CEP109");

    sub[15].push_back(sub150);
    sub[15].push_back(sub151);
    sub[15].push_back(sub152);
    sub[15].push_back(sub153);
    sub[15].push_back(sub154);
    sub[15].push_back(sub155);
    sub[15].push_back(sub156);
    sub[15].push_back(sub157);
    sub[15].push_back(sub158);

//----------------------------16. Data for mtech EC sem III--------------------------------------------//   

    subject sub160("CT425","RF and Antenna Engineering",3,3,"DKG","CEP107"),
    sub161("CT437","Speech Communication",3,3,"HP","CEP109"),
    sub162("CT425","RF and Antenna Engineering",3,3,"DKG","CEP003");

    sub[16].push_back(sub160);
    sub[16].push_back(sub161);
    sub[16].push_back(sub162);

//----------------------------17. Data for msc IT sem I--------------------------------------------//   

    subject sub170("PC613","Communication Skills",3,0,"JJ","CEP207"),
    sub171("IT623","Data Structures",3,0,"RM2","CEP209"),
    sub172("IT615","Database Management Systems",3,0,"MK","CEP207"),
    sub173("SC612","Discrete Mathematics",3,0,"GP","CEP209"),
    sub174("IT603","Introduction to Programming",3,0,"LS","CEP207");

    sub[17].push_back(sub170);
    sub[17].push_back(sub171);
    sub[17].push_back(sub172);
    sub[17].push_back(sub173);
    sub[17].push_back(sub174);

//----------------------------18. Data for msc DS sem I--------------------------------------------//   

    subject sub180("SC613","Mathematical Foundation for Data Science",3,0,"BC","CEP212"),
    sub181("SC614","Statistical Methods (Lab:R)",3,0,"TB","CEP210"),
    sub182("IT605","Data Structures and Algorithms (with Python)",3,0,"RM","CEP107"),
    sub183("IT607","Database Management Systems",3,0,"MB","CEP105");

    sub[18].push_back(sub180);
    sub[18].push_back(sub181);
    sub[18].push_back(sub182);
    sub[18].push_back(sub183);
    
//----------------------------19. Data for msc IT sem III--------------------------------------------//   

    subject sub190("IT619","Design of Software Systems",3,0,"JP","CEP207"),
    sub191("IT618","Enterprise Computing",3,0,"PMJ","CEP209"),
    sub192("IT634","Information Systems Security",3,3,"MLD","CEP107"),
    sub193("IT627","Cloud Computing",3,3,"LS","CEP109"),
    sub194("IT414","Software Project Management",3,3,"JP","CEP210"),
    sub195("HM403","Corporate Finance",3,3,"CJ","CEP212"),
    sub196("HM333","Human Behaviour Management",3,3,"N Banerjee","CEP210"),
    sub197("HM492","Design Thinking",2,3,"GV","CEP212");

    sub[19].push_back(sub190);
    sub[19].push_back(sub191);
    sub[19].push_back(sub192);
    sub[19].push_back(sub193);
    sub[19].push_back(sub194);
    sub[19].push_back(sub195);
    sub[19].push_back(sub196);
    sub[19].push_back(sub197);

//----------------------------20. Data for msc DS sem III--------------------------------------------//   

    subject sub200("IT641","Deep Learning",3,0,"BG","CEP212"),
    sub201("IT642","Interactive Data Visualization",3,0,"BC","CEP210"),
    sub202("HM403","Corporate Finance",3,3,"CJ","CEP109"),
    sub203("HM333","Human Behaviour Management",3,3,"N Banerjee","CEP107"),
    sub204("HM492","Design Thinking",2,3,"GV","CEP104");

    sub[20].push_back(sub200);
    sub[20].push_back(sub201);
    sub[20].push_back(sub202);
    sub[20].push_back(sub203);
    sub[20].push_back(sub204);

//----------------------------21. Data for phd--------------------------------------------//   

    subject sub210("HM710","PhD Colloquium",3,0,"HASS Faculty","CEP108"),
    sub211("HM702","Realism and Aestheticism",3,0,"HASS Faculty","CEP106");

    sub[21].push_back(sub210);
    sub[21].push_back(sub211);
    
    
    /*
   
   
   for(int j=0;j<sub.size();++j){
   vector<subject> test;
   test = weeklecvec(j);
   
   
    cout<<test.size()<<endl;
   for(int i=0;i<test.size();++i){
        cout<<test[i].code<<" "<<test[i].name<<endl;
   }

   cout<<endl;
   }
   */
int choice ;

while(choice !=22){
   
   cout<<"0. Data for btech ict sem I sec A\n"<<
"1. Data for btech ICT sem I sec B\n"<<
"2. Data for btech EVD sem I\n"<<
"3. Data for btech MnC sem I \n"<<
"4. Data for btech Ict sem III sec a\n"<<
"5. Data for btech Ict sem III sec b\n"<<
"6. Data for btech mnc sem III\n"<<
"7. Data for btech ict sem V\n"<<
"8. Data for btech ictCS sem V\n"<<
"9. Data for btech Mnc sem V\n"<<
"10. Data for btech ICT + CS sem VII\n"<<
"11. Data for btech ICT CS only sem VII\n"<<
"12. Data for mtech ICT sem I\n"<<
"13. Data for mtech EC sem I\n"<<
"14. Data for mtech ICT sem III\n"<<
"15. Data for btech mnc sem VII\n"<<
"16. Data for mtech EC sem III\n"<<
"17. Data for msc IT sem I\n"<<
"18. Data for msc DS sem I\n"<<
"19. Data for msc IT sem III\n"<<
"20. Data for msc DS sem III\n"<<
"21. Data for phd\n"<<
"22. To escape...\n\n";



cin>>choice ;

if(choice ==0   ){
    
    freeslotassign(0);
    displaytableindividual(0);
    
}else if(choice ==  1 ){
    
    freeslotassign(1);
    displaytableindividual(1);
    
}else if(choice ==  2 ){
    
    freeslotassign(2);
    displaytableindividual(2);
    
}else if(choice == 3  ){
    
    freeslotassign(3);
    displaytableindividual(3);
    
}else if(choice == 4  ){
    
    freeslotassign(4);
    displaytableindividual(4);
    
}else if(choice == 5  ){
    
    freeslotassign(5);
    displaytableindividual(5);
    
}else if(choice == 6  ){
    
    freeslotassign(6);
    displaytableindividual(6);
    
}else if(choice ==  7 ){
    
    freeslotassign(7);
    displaytableindividual(7);
    
}else if(choice ==  8 ){
    
    freeslotassign(8);
    displaytableindividual(8);
    
}else if(choice ==  9 ){
    
    freeslotassign(9);
    displaytableindividual(9);
    
}else if(choice ==  10 ){
    
    freeslotassign(10);
    displaytableindividual(10);
    
}else if(choice == 11  ){
    
    freeslotassign(11);
    displaytableindividual(11);
    
}else if(choice ==12   ){
    
    freeslotassign(12);
    displaytableindividual(12);
    
}else if(choice ==13   ){
    
    freeslotassign(13);
    displaytableindividual(13);
    
}else if(choice ==14   ){
    
    freeslotassign(14);
    displaytableindividual(14);
    
}else if(choice ==15   ){
    
    freeslotassign(15);
    displaytableindividual(15);
    
}else if(choice ==16   ){
    
    freeslotassign(16);
    displaytableindividual(16);
    
}else if(choice ==17   ){
    
    freeslotassign(17);
    displaytableindividual(17);
    
}else if(choice ==18   ){
    
    freeslotassign(18);
    displaytableindividual(18);
    
}else if(choice ==19   ){
    
    freeslotassign(19);
    displaytableindividual(19);
    
}else if(choice == 20  ){
    
    freeslotassign(20);
    displaytableindividual(20);
    
}else if(choice ==  21 ){
    
    freeslotassign(21);
    displaytableindividual(21);
    
}
}


}

else{
 
    sub.resize(18);
    
//----------------------------0.btech ICT sem II--------------------------------------------//  

    subject sub00("HM106", "Approaches to Indian Society", 3, 0, "BK","LT1"),
    sub01("IC121", "Digital Logic and Computer Organization", 3, 0, "SR","LT1"),
    sub02("IT205", "Data Structures", 3, 0, "SDG","CEP110"),
    sub03("IT206", "Data Structure Lab using OOP", 1, 0, "PhD Scholar","LT2"),
    sub04("SC205", "Discrete Mathematics", 3, 0, "AT2","LT2"),
    sub05("SC217", "Electromagnetic Theory", 3, 0, "GD","LT3");

    sub[0].push_back(sub00);
    sub[0].push_back(sub01);
    sub[0].push_back(sub02);
    sub[0].push_back(sub03);
    sub[0].push_back(sub04);
    sub[0].push_back(sub05);
    

//----------------------------1.btech CS sem II--------------------------------------------// 

    subject sub10("HM106", "Approaches to Indian Society", 3, 0, "BK","LT2"),
    sub11("IC121", "Digital Logic and Computer Organization", 3, 0, "SR","LT1"),
    sub12("IT205", "Data Structures", 3,0, "SDG","CEP102"),
    sub13("IT206", "Data Structure Lab using OOP", 1,0, "PhD Scholar","LT2"),
    sub14("SC205", "Discrete Mathematics", 3,0, "AT2","LT3"),
    sub15("SC217", "Electromagnetic Theory", 3,0, "GD","LT3");

    sub[1].push_back(sub10);
    sub[1].push_back(sub11);
    sub[1].push_back(sub12);
    sub[1].push_back(sub13);
    sub[1].push_back(sub14);
    sub[1].push_back(sub15);

//----------------------------2.btech MNC sem II--------------------------------------------// 

    subject sub20("HM106", "Approaches to Indian Society", 3,0, "BK","LT2"),
    sub21("MC215", "Linear Algebra", 3,0, "SB2","CEP205"),
    sub22("MC122", "Object Oriented Programming", 2,0, "TBD","CEP205"),
    sub23("MC125", "Functions of Single Variable and ODEs", 3,0, "MS","CEP205"),
    sub24("MC124", "Data Structures and Algorithms", 3,0, "RM2","CEP205");

    sub[2].push_back(sub20);
    sub[2].push_back(sub21);
    sub[2].push_back(sub22);
    sub[2].push_back(sub23);
    sub[2].push_back(sub24);

//----------------------------3.btech EVD sem II--------------------------------------------// 

    subject sub30("HM106", "Approaches to Indian Society", 3, 0, "BK","LT2"),
    sub31("ED121", "Engineering Mathematics II", 3, 0, "PK2","CEP105"),
    sub32("IC121", "Digital Logic and Computer Organization", 3, 0, "SR","LT1"),
    sub33("IT205", "Data Structures", 3, 0,"SDG","CEP102"),
    sub34("IT206", "Data Structure Lab using OOP", 1, 0, "PhD Scholar","LT2"),
    sub35("SC217", "Electromagnetic Theory", 3, 0, "GD","LT3");

    sub[3].push_back(sub30);
    sub[3].push_back(sub31);
    sub[3].push_back(sub32);
    sub[3].push_back(sub33);
    sub[3].push_back(sub34);
    sub[3].push_back(sub35);

//----------------------------4.btech ICT sem IV--------------------------------------------//

    subject sub40("HM116", "Principles of Economics", 3, 0, "Gaurav","CEP110"),
    sub41("EL203", "Embedded Hardware Design", 3, 0, "BM","LT2"),
    sub42("IT214", "Database Management System", 3, 0, "PMJ","LT3"),
    sub43("CT216", "Introduction to Communication Systems", 3, 0, "YV","LT3"),
    sub44("SC224", "Probability and Statistics", 3, 0, "MS","LT2"),
    sub45("IT422", "Models of Computation", 3, 3, "RM","CEP106"),
    sub46("IE402", "Optimization", 3, 3, "MKR","CEP103"),
    sub47("IE410", "Introduction to Robotics", 3, 3, "TKM","CEP106");

    sub[4].push_back(sub40);
    sub[4].push_back(sub41);
    sub[4].push_back(sub42);
    sub[4].push_back(sub43);
    sub[4].push_back(sub44);
    sub[4].push_back(sub45);
    sub[4].push_back(sub46);
    sub[4].push_back(sub47);

//----------------------------5.btech CS sem IV--------------------------------------------//

    subject sub50("HM116", "Principles of Economics", 3, 0, "Gaurav","CEP102"),
    sub51("EL203", "Embedded Hardware Design", 3, 0, "BM","LT3"),
    sub52("IT214", "Database Management System", 3, 0, "PMJ","LT3"),
    sub53("CT216", "Introduction to Communication Systems", 3, 0, "YV","LT3"),
    sub54("SC224", "Probability and Statistics", 3, 0, "MS","LT2"),
    sub55("IT422", "Models of Computation", 3, 3, "RM","CEP106"),
    sub56("IE402", "Optimization", 3, 3, "MKR","CEP103"),
    sub57("IE410", "Introduction to Robotics", 3, 3, "TKM","CEP106"),
    sub58("CS201", "Introductory Computational Physics", 3,0, "AR","CEP205");

    sub[5].push_back(sub50);
    sub[5].push_back(sub51);
    sub[5].push_back(sub52);
    sub[5].push_back(sub53);
    sub[5].push_back(sub54);
    sub[5].push_back(sub55);
    sub[5].push_back(sub56);
    sub[5].push_back(sub57);
    sub[5].push_back(sub58);

//----------------------------6.btech MNC sem IV--------------------------------------------//

    subject sub60("MC221", "Mathematical Statistics", 3, 0, "GP","CEP206"),
    sub61("MC222", "Real and Complex Analysis", 3, 0, "NKS","CEP206"),
    sub62("MC223", "Theory of Computation", 3, 0, "PB","CEP206"),
    sub63("MC224", "Parallel and Distributed Algorithms", 3, 0, "VS","CEP206"),
    sub64("MC225", "Numerical and Computational Methods", 3, 0, "SK","CEP206"),
    sub65("MC226", "Environmental Studies", 2, 0, "RG","LT3");

    sub[6].push_back(sub60);
    sub[6].push_back(sub61);
    sub[6].push_back(sub62);
    sub[6].push_back(sub63);
    sub[6].push_back(sub64);
    sub[6].push_back(sub65);

//----------------------------7.btech ICT sem VI--------------------------------------------//

    subject sub70("CT476", "Microwave Engineering", 3, 23, "PK","CEP110"),
    sub71("CT548", "Advanced Wireless Communication", 3, 23, "MK2","CEP105"),
    sub72("CT547", "Application of ML to Wireless Comm Systems", 3, 23, "AJ","CEP109"),
    sub73("CT491", "Satellite and Space Technology and Its Applications", 3,23, "DKG","CEP102"),
    sub74("EL516", "Analog VLSI Design", 3, 23, "DNC","CEP104"),
    sub75("EL464", "VLSI Testing and Validation", 3, 23, "SR","CEP104"),
    sub76("EL527", "ASIC Design", 3, 24, "RP","CEP108"),
    sub77("EL495", "Sensors & Instrumentation", 3, 23, "VSP","CEP110"),
    sub78("EL496", "Robot Programming (RAS minor 6th Sem)", 3, 23, "TKM","CEP106"),
    sub79("IE404", "Digital Image Processing", 3, 5, "MK","CEP109"),
    sub710("EL497", "Autonomous Vehicles", 3, 23, "SK","CEP106"),
    sub711("IT422", "Models of Computation", 3, 23, "RM","CEP106"),
    sub712("IT457", "Cloud Computing", 3, 23, "LS","CEP102"),
    sub713("IT492", "Recommendation Systems", 3, 23, "AR2","CEP110"),
    sub714("IT449", "Specification and Verification of Systems", 3, 23, "PB","CEP106"),
    sub715("IT590", "Advanced Statistical Tools for Data Science", 3, 23, "TB","CEP110"),
    sub716("IT559", "Distributed Systems", 3, 23, "PKS","CEP103"),
    sub717("IT504", "Distributed Databases", 3, 23, "MB","CEP105"),
    sub718("IT412", "Natural Language Processing", 3, 23, "SDG","LT2"),
    sub719("IT583", "Deep Learning", 3, 23, "BG","CEP108"),
    sub720("IT544", "Modern Cryptography", 3, 23, "MLD","CEP105"),
    sub721("IT495", "Exploratory Data Analysis", 3, 23, "GP","CEP108"),
    sub722("IT584", "Approximation Algorithms", 3, 23, "RC","CEP108"),
    sub723("IT561", "Advanced Software Engineering", 3, 23, "ST","CEP105"),
    sub724("SC407", "Environmental Science", 3, 0, "YV","LT3"),
    sub725("IE406", "Machine Learning", 3,5, "SM","CEP110"),
    sub726("IE410", "Introduction to Robotics", 3, 5, "TKM","CEP106"),
    sub727("IE411", "Operating Systems", 3, 5, "AMM","CEP102"),
    sub728("IE403", "Human Computer Interaction", 3, 5, "PKS","CEP108");
    

    sub[7].push_back(sub70);
    sub[7].push_back(sub71);
    sub[7].push_back(sub72);
    sub[7].push_back(sub73);
    sub[7].push_back(sub74);
    sub[7].push_back(sub75);
    sub[7].push_back(sub76);
    sub[7].push_back(sub77);
    sub[7].push_back(sub78);
    sub[7].push_back(sub79);
    sub[7].push_back(sub710);
    sub[7].push_back(sub711);
    sub[7].push_back(sub712);
    sub[7].push_back(sub713);
    sub[7].push_back(sub714);
    sub[7].push_back(sub715);
    sub[7].push_back(sub716);
    sub[7].push_back(sub717);
    sub[7].push_back(sub718);
    sub[7].push_back(sub719);
    sub[7].push_back(sub720);
    sub[7].push_back(sub721);
    sub[7].push_back(sub722);
    sub[7].push_back(sub723);
    sub[7].push_back(sub724);
    sub[7].push_back(sub725);
    sub[7].push_back(sub726);
    sub[7].push_back(sub727);
    sub[7].push_back(sub728);

//----------------------------8.btech CS sem VI--------------------------------------------//

    subject sub80("CT476", "Microwave Engineering", 3, 23, "PK","CEP110"),
    sub81("CT548", "Advanced Wireless Communication", 3, 23, "MK2","CEP105"),
    sub82("CT547", "Application of ML to Wireless Comm Systems", 3, 23, "AJ","CEP109"),
    sub83("CT491", "Satellite and Space Technology and Its Applications", 3,23, "DKG","CEP102"),
    sub84("IE404", "Digital Image Processing", 3, 5, "MK","CEP109"),
    sub85("EL516", "Analog VLSI Design", 3, 23, "DNC","CEP104"),
    sub86("EL464", "VLSI Testing and Validation", 3, 23, "SR","CEP104"),
    sub87("EL527", "ASIC Design", 3, 24, "RP","CEP108"),
    sub88("EL495", "Sensors & Instrumentation", 3, 23, "VSP","CEP110"),
    sub89("EL496", "Robot Programming (RAS minor 6th Sem)", 3, 23, "TKM","CEP106"),
    sub810("EL497", "Autonomous Vehicles", 3, 23, "SK","CEP106"),
    sub811("IT422", "Models of Computation", 3, 23, "RM","CEP106"),
    sub812("IT457", "Cloud Computing", 3, 23, "LS","CEP102"),
    sub813("IT492", "Recommendation Systems", 3, 23, "AR2","CEP110"),
    sub814("IT449", "Specification and Verification of Systems", 3, 23, "PB","CEP106"),
    sub815("IT590", "Advanced Statistical Tools for Data Science", 3, 23, "TB","CEP110"),
    sub816("IT559", "Distributed Systems", 3, 23, "PKS","CEP103"),
    sub817("IT504", "Distributed Databases", 3, 23, "MB","CEP105"),
    sub818("IT412", "Natural Language Processing", 3, 23, "SDG","LT2"),
    sub819("IT583", "Deep Learning", 3, 23, "BG","CEP108"),
    sub820("IT544", "Modern Cryptography", 3, 23, "MLD","CEP105"),
    sub821("IT495", "Exploratory Data Analysis", 3, 23, "GP","CEP108"),
    sub822("IT584", "Approximation Algorithms", 3, 23, "RC","CEP108"),
    sub823("IT561", "Advanced Software Engineering", 3, 23, "ST","CEP105"),
    sub824("SC407", "Environmental Science", 3, 0, "YV","LT3"),
    sub825("IE406", "Machine Learning", 3,5, "SM","CEP110"),
    sub826("IE410", "Introduction to Robotics", 3, 5, "TKM","CEP106"),
    sub827("IE411", "Operating Systems", 3, 5, "AMM","CEP102"),
    sub828("IE403", "Human Computer Interaction", 3, 5, "PKS","CEP108");
    

    sub[8].push_back(sub80);
    sub[8].push_back(sub81);
    sub[8].push_back(sub82);
    sub[8].push_back(sub83);
    sub[8].push_back(sub84);
    sub[8].push_back(sub85);
    sub[8].push_back(sub86);
    sub[8].push_back(sub87);
    sub[8].push_back(sub88);
    sub[8].push_back(sub89);
    sub[8].push_back(sub810);
    sub[8].push_back(sub811);
    sub[8].push_back(sub812);
    sub[8].push_back(sub813);
    sub[8].push_back(sub814);
    sub[8].push_back(sub815);
    sub[8].push_back(sub816);
    sub[8].push_back(sub817);
    sub[8].push_back(sub818);
    sub[8].push_back(sub819);
    sub[8].push_back(sub820);
    sub[8].push_back(sub821);
    sub[8].push_back(sub822);
    sub[8].push_back(sub823);
    sub[8].push_back(sub824);
    sub[8].push_back(sub825);
    sub[8].push_back(sub826);
    sub[8].push_back(sub827);
    sub[8].push_back(sub828);
    
    
//----------------------------9.btech MNC sem VI--------------------------------------------//

    subject sub90("MC321", "Machine Learning", 3, 0, "PA","CEP104"),
    sub91("IT449", "Specification and Verification of Systems", 3, 6, "PB","CEP106"),
    sub92("IT590", "Advanced Statistical Tools for Data Science", 3, 6, "TB","CEP003"),
    sub93("IT559", "Distributed Systems", 3, 6, "PKS","CEP103"),
    sub94("IT504", "Distributed Databases", 3, 6, "MB","CEP105"),
    sub95("IT495", "Exploratory Data Analysis", 3, 6, "GP","CEP108"),
    sub96("IT584", "Approximation Algorithms", 3, 6, "RC","CEP108");

    sub[9].push_back(sub90);
    sub[9].push_back(sub91);
    sub[9].push_back(sub92);
    sub[9].push_back(sub93);
    sub[9].push_back(sub94);
    sub[9].push_back(sub95);
    sub[9].push_back(sub96);
   
//----------------------------10.btech ICT sem VIII--------------------------------------------//

    subject sub100("SC402", "Introduction to Cryptography", 3, 4, "MKG","CEP102"),
    sub101("SC471", "Time Series Analysis", 3, 4, "MT","CEP103"),
    sub102("SC474", "Optical Communication", 3, 4, "AKR",""),
    sub103("SC472", "Econometric Data Analysis Using R", 3, 4, "Gaurav Singh","CEP110"),
    sub104("HM327", "Culture, Politics, Identity", 3, 7, "MM","CEP105"),
    sub105("HM432", "Organisational Behaviour", 3, 7, "N Banerjee","CEP103"),
    sub106("HM402", "Publics in South Asia: Contemporary Perspectives", 3, 7, "SJ","CEP106"),
    sub107("HM488", "India through its Literature", 3, 7, "Amishal Modi","CEP108"),
    sub108("HM489", "International Economy", 3, 7, "Cyril Jos","CEP108"),
    sub109("HM481", "Reading Plato", 3, 7, "BK","102"),
    sub1010("HM492", "Indian Cinema: Lineages and the Present", 3, 7, "JJ","110");

    sub[10].push_back(sub100);
    sub[10].push_back(sub101);
    sub[10].push_back(sub102);
    sub[10].push_back(sub103);
    sub[10].push_back(sub104);
    sub[10].push_back(sub105);
    sub[10].push_back(sub106);
    sub[10].push_back(sub107);
    sub[10].push_back(sub108);
    sub[10].push_back(sub109);
    sub[10].push_back(sub1010);
       
//----------------------------11.btech CS sem VIII--------------------------------------------//

    subject sub110("SC402", "Introduction to Cryptography", 3, 4, "MKG","CEP102"),
    sub111("SC471", "Time Series Analysis", 3, 4, "MT","CEP103"),
    sub112("SC474", "Optical Communication", 3, 4, "AKR",""),
    sub113("SC472", "Econometric Data Analysis Using R", 3, 4, "Gaurav Singh","CEP110"),
    sub114("HM327", "Culture, Politics, Identity", 3, 7, "MM","CEP105"),
    sub115("HM432", "Organisational Behaviour", 3, 7, "N Banerjee","CEP103"),
    sub116("HM402", "Publics in South Asia: Contemporary Perspectives", 3, 7, "SJ","CEP106"),
    sub117("HM488", "India through its Literature", 3, 7, "Amishal Modi","CEP108"),
    sub118("HM489", "International Economy", 3, 7, "Cyril Jos","CEP108"),
    sub119("HM481", "Reading Plato", 3, 7, "BK","102"),
    sub1110("HM492", "Indian Cinema: Lineages and the Present", 3, 7, "JJ","110");

    sub[11].push_back(sub110);
    sub[11].push_back(sub111);
    sub[11].push_back(sub112);
    sub[11].push_back(sub113);
    sub[11].push_back(sub114);
    sub[11].push_back(sub115);
    sub[11].push_back(sub116);
    sub[11].push_back(sub117);
    sub[11].push_back(sub118);
    sub[11].push_back(sub119);
    sub[11].push_back(sub1110);

//----------------------------12.btech MNC sem VIII--------------------------------------------//

    subject sub120("SC402", "Introduction to Cryptography", 3, 4, "MKG","CEP102"),
    sub121("SC471", "Time Series Analysis", 3, 4, "MT","CEP103"),
    sub122("SC474", "Optical Communication", 3, 4, "AKR","CEP104"),
    sub123("SC472", "Econometric Data Analysis Using R", 3,4, "Gaurav Singh","CEP110");

    sub[12].push_back(sub120);
    sub[12].push_back(sub121);
    sub[12].push_back(sub122);
    sub[12].push_back(sub123);
           
//----------------------------13. MTECH ICT sem II--------------------------------------------//

    subject sub130("IT561", "Advanced Software Engineering", 3, 0, "ST","CEP105"),
    sub131("IT558", "Information Security", 3, 14, "AMM","CEP107"),
    sub132("IT544", "Modern Cryptography", 3, 14, "MLD","CEP105"),
    sub133("IT584", "Approximation Algorithms", 3, 14, "RC","CEP108"),
    sub134("IT504", "Distributed Databases", 3, 14, "MB","CEP105"),
    sub135("IT559", "Distributed Systems", 3, 14, "PKS","CEP103"),
    sub136("IT585", "Advanced Machine Learning", 3, 0, "RC","CEP109"),
    sub137("IE404", "Digital Image Processing", 3, 14, "MK","CEP109"),
    sub138("IT412", "Natural Language Processing", 3, 14, "SDG","LT2"),
    sub139("IT583", "Deep Learning", 3, 14, "BG","CEP108"),
    sub1310("IT492", "Recommendation Systems", 3, 14, "AR2","CEP110"),
    sub1311("EL529", "Embedded Hardware Design", 3, 0, "VSP","CEP107"),
    sub1312("EL527", "ASIC Design", 3, 14, "RP","CEP108"),
    sub1313("EL516", "Analog VLSI Design", 3, 14, "DNC","CEP104"),
    sub1314("EL495", "Sensors & Instrumentation", 3, 14, "VSP","CEP110"),
    sub1315("EL464", "VLSI Testing and Validation", 3, 14, "SR","CEP104"),
    sub1316("EL496", "Robot Programming", 3, 14, "TKM","CEP106");

    sub[13].push_back(sub130);
    sub[13].push_back(sub131);
    sub[13].push_back(sub132);
    sub[13].push_back(sub133);
    sub[13].push_back(sub134);
    sub[13].push_back(sub135);
    sub[13].push_back(sub136);
    sub[13].push_back(sub137);
    sub[13].push_back(sub138);
    sub[13].push_back(sub139);
    sub[13].push_back(sub1310);
    sub[13].push_back(sub1311);
    sub[13].push_back(sub1312);
    sub[13].push_back(sub1313);
    sub[13].push_back(sub1314);
    sub[13].push_back(sub1315);
    sub[13].push_back(sub1316);

//----------------------------14. MTECH EC sem II--------------------------------------------//

    subject sub140("CT421", "Advanced Digital Signal Processing", 3, 0, "HP","CEP109"),
    sub141("CT548", "Advanced Wireless Communication", 3, 4, "MK2","CEP105"),
    sub142("CT547", "Application of ML to Wireless Comm Systems", 3, 4, "AJ","CEP109"),
    sub143("IE404", "Digital Image Processing", 3, 4, "MK","CEP109");

    sub[14].push_back(sub140);
    sub[14].push_back(sub141);
    sub[14].push_back(sub142);
    sub[14].push_back(sub143);

//----------------------------15. msc it sem II--------------------------------------------//

    subject sub150("IT620", "Object Oriented Programming", 3, 0, "TBD","CEP207"),
    sub151("IT632", "Software Engineering", 3, 0, "JP","CEP207"),
    sub152("IT694", "Computer Networks", 3, 0, "SS","CEP207"),
    sub153("IT628", "System Prpgramming", 3, 0, "AKM","CEP207"),
    sub154("IT629", "Introduction to Algorithms", 3, 0, "TBD","CEP207");

    sub[15].push_back(sub150);
    sub[15].push_back(sub151);
    sub[15].push_back(sub152);
    sub[15].push_back(sub153);
    sub[15].push_back(sub154);

//----------------------------16. msc DS sem II--------------------------------------------//

    subject sub160("SC602", "Numerical Methods for Data Science", 3, 0, "NKS","LAB A-SF"),
    sub161("SC601", "Optimization", 2, 0, "AT","LAB A-SF"),
    sub162("IT608", "Machine Learning", 3, 0, "SB","LAB A-SF"),
    sub163("IT609", "Big Data Processing", 2, 0, "TBD","LAB A-SF"),
    sub164("IT590", "Advanced Statistical Tools for Data Science", 3, 4, "TB","CEP212"),
    sub165("IT412", "Natural Language Processing", 3, 4, "SDG","LT2"),
    sub166("IT495", "Exploratory Data Analysis", 3, 4, "GP","CEP110"),
    sub167("IT492", "Recommendation Systems", 3, 4, "AR2","CEP110");

    sub[16].push_back(sub160);
    sub[16].push_back(sub161);
    sub[16].push_back(sub162);
    sub[16].push_back(sub163);
    sub[16].push_back(sub164);
    sub[16].push_back(sub165);
    sub[16].push_back(sub166);
    sub[16].push_back(sub167);

//----------------------------17.PHD students--------------------------------------------//

    subject sub170("PC874","Research Methodology",3,0,"AG","CEP104");

    sub[17].push_back(sub170);
    
int ch;

while(ch!=18){    

 cout<<"0.btech ICT sem II\n"<<
 "1.btech CS sem II-\n"<<
 "2.btech MNC sem II\n"<<
 "3.btech EVD sem II-\n"<<
 "4.btech ICT sem IV-\n"<<
 "5.btech CS sem IV-\n"<<
 "6.btech MNC sem IV---\n"<<
 "7.btech ICT sem VI---\n"<<
 "8.btech CS sem VI--\n"<<
"9.btech MNC sem VI-\n"<<
 "10.btech ICT sem VIII--\n"<<
 "11.btech CS sem VIII----\n"<<
"12.btech MNC sem VIII---\n"<<
"13.MTECH ICT sem II-\n"<<
"14.MTECH EC sem II-\n"<<
"15.msc it sem II-\n"<<
"16.msc DS sem II----\n"<<
"17.PHD students\n"<<
"18. To escape...\n\n";

cin>>ch;

if(ch ==   0 ){
    
    freeslotassign( 0 );
    displaytableindividual( 0  );

}else if(ch ==  1  ){
    
    freeslotassign(1  );
    displaytableindividual( 1);

}else if(ch ==  2  ){
    
    freeslotassign( 2 );
    displaytableindividual(2   );

}else if(ch ==  3  ){
    
    freeslotassign( 3 );
    displaytableindividual(   3);

}else if(ch ==   4 ){
    
    freeslotassign(  4);
    displaytableindividual( 4  );

}else if(ch ==  5  ){
    
    freeslotassign(5  );
    displaytableindividual(  5 );

}else if(ch == 6   ){
    
    freeslotassign( 6 );
    displaytableindividual(   6);

}else if(ch ==   7 ){
    
    freeslotassign(7  );
    displaytableindividual(   7);

}else if(ch ==   8 ){
    
    freeslotassign(8  );
    displaytableindividual(  8 );

}else if(ch == 9   ){
    
    freeslotassign(  9);
    displaytableindividual( 9  );

}else if(ch == 10   ){
    
    freeslotassign( 10 );
    displaytableindividual(  10 );

}else if(ch == 11   ){
    
    freeslotassign( 11 );
    displaytableindividual(  11 );

}else if(ch == 12   ){
    
    freeslotassign( 12 );
    displaytableindividual(  12 );

}else if(ch ==   13 ){
    
    freeslotassign( 13 );
    displaytableindividual(  13 );

}else if(ch == 14   ){
    
    freeslotassign( 14 );
    displaytableindividual(  14 );

}else if(ch == 15   ){
    
    freeslotassign(15  );
    displaytableindividual(  15 );

}else if(ch == 16   ){
    
    freeslotassign(  16);
    displaytableindividual(  16 );

}else if(ch ==  17  ){
    
    freeslotassign( 17 );
    displaytableindividual(  17 );

}


}

}

cout<<"Thank you...";
  return 0;
  
  
}
