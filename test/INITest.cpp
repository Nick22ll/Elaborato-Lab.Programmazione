//
// Created by niccolo on 14/09/18.
//

#include<gtest/gtest.h>
#include"../INI.h"



TEST(INITest, ParamTest) {

    INI file("/home/niccolo/CLionProjects/Uni_INI/resources/Testo.txt");
    //Test addParam
    EXPECT_EQ(file.addParam("Arance","60","Frutta e Verdura"),no_error);
    EXPECT_EQ(file.addParam("Arance","60","Frutta e Verdura"),duplicate);
    EXPECT_EQ(file.addParam("Mele","60","Frutta e Verdura"),duplicate);
    EXPECT_EQ(file.addParam("Arance","60","Carni"),not_exist);

    //test changeParam
    EXPECT_EQ(file.changeParam("Arance","20","Frutta e Verdura"),no_error);
    EXPECT_EQ(file.changeParam("Cavolo","20","Farinati"),not_exist);
    EXPECT_EQ(file.changeParam("Arce","20","Frutta e Verdura"),not_exist);

    //test renameParam
    EXPECT_EQ(file.renameParam("Arance","Carote","Frutta e Verdura"),duplicate);
    EXPECT_EQ(file.renameParam("Arance","Tarocco","Surgelati"),not_exist);
    EXPECT_EQ(file.renameParam("Cavolo","Tarocco","Frutta e Verdura"),not_exist);
    EXPECT_EQ(file.renameParam("Arance","Tarocco","Frutta e Verdura"),no_error);

    //Test getParam
    string str;
    EXPECT_EQ(file.getParam(str,"Tarocco","Surgelati"),not_exist);
    EXPECT_EQ(file.getParam(str,"Pesce","Frutta e Verdura"),not_exist);
    EXPECT_EQ(file.getParam(str,"Tarocco","Frutta e Verdura"),no_error);
    EXPECT_TRUE(str == "20");

    //Test delParam
    EXPECT_EQ(file.delParam("Tarocco","Surgelati"),not_exist);
    EXPECT_EQ(file.delParam("Cavolo","Frutta e Verdura"),not_exist);
    EXPECT_EQ(file.delParam("Tarocco","Frutta e Verdura"),no_error);

}

TEST(INITest, SectionTest)
{
    INI file("/home/niccolo/CLionProjects/Uni_INI/resources/Testo.txt");

    //Test addSection
    EXPECT_EQ(file.addSection("Carni"),no_error);
    EXPECT_EQ(file.addSection("Farinati"),duplicate);
    EXPECT_EQ(file.addSection("Carni"),duplicate);
    EXPECT_EQ(file.addParam("Brasato","10","Carni"),no_error);
    EXPECT_EQ(file.addParam("Rosticciana","60","Carni"),no_error);
    EXPECT_EQ(file.delParam("Brasato","Carni"),no_error);

    //Test renameSection
    EXPECT_EQ(file.renameSection("Carni","Frutta e Verdura"),duplicate);
    EXPECT_EQ(file.renameSection("Pesce","Frutta e Verdura"),not_exist);
    EXPECT_EQ(file.renameSection("Carni","Macelleria"),no_error);

    //Test delSection
    EXPECT_EQ(file.delSection("Pesce"),not_exist);
    EXPECT_EQ(file.delSection("Macelleria"),no_error);

}


TEST(INITest, CommentTest) {

    INI file("/home/niccolo/CLionProjects/Uni_INI/resources/Testo.txt");

    //Test addComment (Parameter)
    EXPECT_EQ(file.addComment("Fresco di giornata","Pane","Farinati"),no_error);
    EXPECT_EQ(file.addComment("Fresco di giornata","Pane","Farinati"),duplicate);
    EXPECT_EQ(file.addComment("Fresco di giornata","Burro","Farinati"),not_exist);
    EXPECT_EQ(file.addComment("Fresco di giornata","Pane","Carni"),not_exist);

    //Test addComment (Section)
    EXPECT_EQ(file.addComment("Sono tutti ghiacciati","Surgelati"),no_error);
    EXPECT_EQ(file.addComment("Sono tutti ghiacciati","Surgelati"),duplicate);
    EXPECT_EQ(file.addComment("Sono tutti ghiacciati","Frighi"),not_exist);

    //test getComment (Section)
    string str;
    EXPECT_EQ(file.getComment(str,"Surgelati"),no_error);
    EXPECT_TRUE(str == ";Sono tutti ghiacciati")<<"Str=  "<<str;
    EXPECT_EQ(file.getComment(str,"Sulati"),not_exist);

    //Test getComment (Parameter)
    EXPECT_EQ(file.getComment(str,"Surgelati","LinguinealloScoglio"),no_error);
    EXPECT_TRUE(str == ";Novità offerta")<<"str e': "<<str;
    EXPECT_EQ(file.getComment(str,"Selati","LinguinealloScoglio"),not_exist);
    EXPECT_EQ(file.getComment(str,"Surgelati","LinguineScoglio"),not_exist);

    //Test delComment (Section)
    EXPECT_EQ(file.delComment("Sgelati"),not_exist);
    EXPECT_EQ(file.delComment("Surgelati"),no_error);

    //Test delComment (Section)
    EXPECT_EQ(file.delComment("Faati","Pane"),not_exist);
    EXPECT_EQ(file.delComment("Farinati","Pe"),not_exist);
    EXPECT_EQ(file.delComment("Farinati","Pane"),no_error);



}
