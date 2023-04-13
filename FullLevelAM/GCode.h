//
// Created by MBP on 2023/4/12.
//

#ifndef GCODE_GCODE_H
#define GCODE_GCODE_H
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cfloat>
#include <fstream>
namespace gcode{
    const double doubleNull = DBL_MAX;

//avoid open and close each time write()
    std::ofstream outfile;

//avoid created each time doubleToString()
    std::stringstream stringTem;

//open file at begining
    void openFile(std::string filePath) {
        outfile.open(filePath, std::ios::app);
    }

//write text into filePath.txt
    void write(std::string text) {
        if (!outfile)
        {
            std::cout << "file not open!" << std::endl;
            exit(1);
        }
        std::cout<<text<<std::endl;
        outfile << text << std::endl;
    }

//close file at the end
    void closeFile() {
        outfile.close();
    }

    std::string doubleToString(double number, int precision) {
        stringTem.str("");
        stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << number;
        return stringTem.str();
    }

    std::string doubleToString(int number) {
        stringTem.str("");
//        stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << number;
        stringTem << std::setiosflags(std::ios::fixed) << number;
        return stringTem.str();
    }


    std::string doubleToString(double number) {
        return doubleToString(number, 1);
    }

    std::string appendIfNotNull(std::string attribute, double value) {
        if (value != doubleNull) {
            return attribute + doubleToString(value);
        }
        else return "";
    }

    std::string appendIfNotNull(std::string attribute, int value) {
        if (value != doubleNull) {
            return attribute + doubleToString(value);
        }
        else return "";
    }

    std::string appendIfNotNull(std::string attribute, std::string str) {
        if (str != "") {
            return attribute + str;
        }
        else return "";
    }

    void G00( double x, double y, double z, double f1) {
        std::string text = "G00";
        if (f1 != doubleNull) {
            text += " P1";
        }
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" F1", f1);
        write(text);
    }

    void G01( double x, double y, double z, double f) {
        std::string text = "G01";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G024( double x1, double y1, double z1, double axial1, double axial2, double f, double x2, double y2, double z2, double axial3, double axial4) {
        std::string text1 = "G02.4";
        text1 += appendIfNotNull(" X", x1);
        text1 += appendIfNotNull(" Y", y1);
        text1 += appendIfNotNull(" Z", z1);
        text1 += appendIfNotNull(" α", axial1);
        text1 += appendIfNotNull(" β", axial2);
        text1 += appendIfNotNull(" F", f);
        write(text1);

        std::string text2 = "";
        text2 += appendIfNotNull("X", x2);
        text2 += appendIfNotNull(" Y", y2);
        text2 += appendIfNotNull(" Z", z2);
        text2 += appendIfNotNull(" α", axial3);
        text2 += appendIfNotNull(" β", axial4);
        write(text2);
    }

    void G034( double x1, double y1, double z1, double axial1, double axial2, double f, double x2, double y2, double z2, double axial3, double axial4) {
        std::string text1 = "G03.4";
        text1 += appendIfNotNull(" X", x1);
        text1 += appendIfNotNull(" Y", y1);
        text1 += appendIfNotNull(" Z", z1);
        text1 += appendIfNotNull(" α", axial1);
        text1 += appendIfNotNull(" β", axial2);
        text1 += appendIfNotNull(" F", f);
        write(text1);

        std::string text2 = "";
        text2 += appendIfNotNull("X", x2);
        text2 += appendIfNotNull(" Y", y2);
        text2 += appendIfNotNull(" Z", z2);
        text2 += appendIfNotNull(" α", axial3);
        text2 += appendIfNotNull(" β", axial4);
        write(text2);
    }

    void G02( int model, double x, double y, double r, double z, double f) {
        std::string text = "";
        text += appendIfNotNull("G", model);
        text += " G02";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G02( int model, double x, double y, double i, double j, double z, double f) {
        std::string text = "";
        text += appendIfNotNull("G", model);
        text += "G02";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" I", i);
        text += appendIfNotNull(" J", j);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G03( int model, double x, double y, double r, double z, double f) {
        std::string text = "";
        text += appendIfNotNull("G", model);
        text += "G03";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G03( int model, double x, double y, double i, double j, double z, double f) {
        std::string text = "";
        text += appendIfNotNull("G", model);
        text += "G03";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" I", i);
        text += appendIfNotNull(" J", j);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G02_G03( int model, double x, double y, double z, double ijk1, double ijk2, double l, double f) {
        std::string text = "";
        text += appendIfNotNull("G", model);
        text += "G02/G03";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        if(x == doubleNull){
            text += appendIfNotNull(" J", ijk1);
            text += appendIfNotNull(" K", ijk2);
        }
        else if(y == doubleNull){
            text += appendIfNotNull(" I", ijk1);
            text += appendIfNotNull(" K", ijk2);
        }
        else{
            text += appendIfNotNull(" I", ijk1);
            text += appendIfNotNull(" J", ijk2);
        }
        text += appendIfNotNull(" L", l);
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G041( int p, int q) {
        std::string text = "";
        text += "G04.1";
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" Q", q);
        write(text);
    }

    void G04(double xp) {
        std::string text = "";
        text += "G04";
        if(xp == (int)xp){
            text += appendIfNotNull(" P", xp);
        }
        else{
            text += appendIfNotNull(" X", xp);
        }
        write(text);
    }

    void G051( int q, int e) {
        std::string text = "";
        text += "G05.1";
        text += appendIfNotNull(" Q", q);
        text += appendIfNotNull(" E", e);
        write(text);
    }

    void G05( int p, int e) {
        std::string text = "";
        text += "G05";
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" E", e);
        write(text);
    }

    void G05( int p, int x, int y, int z, std::string α, std::string β) {
        std::string text = "";
        text += "G05";
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" α", α);
        text += appendIfNotNull(" β", β);
        write(text);
    }

    void G062(int model, int p, double k, double x, double y, double z, double r, double f){
        std::string text = "";
        text += "G062";
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" K", k);
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G61(double x, double y, double z){
        std::string text = "";
        text += "G61";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        write(text);

        std::string text1 = "G61";
        write(text1);
    }

    void G09(double x, double y, double z){
        std::string text = "";
        text += "G09";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        write(text);

        std::string text1 = "G61";
        write(text1);
    }

    void G10(int l, double p, double r){
        std::string text = "";
        text += "G10";
        text += appendIfNotNull(" L", l);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" R", r);
        write(text);
    }

    void G109(int x, int y, int z){
        std::string text = "";
        text += "G10.9";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        write(text);
    }

    void G121(double x, double c){
        std::string text = "";
        text += "G12.1";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" C", c);
        write(text);
    }

    void G131(){
        write("G13.1");
    }

    void G16(){
        write("G16");
    }

    void G15(){
        write("G15");
    }

    void G17(){
        write("G17");
    }

    void G18(){
        write("G18");
    }

    void G19(){
        write("G19");
    }

    void G22(double x, double y, double z, double i, double j, double k){
        std::string text = "";
        text += "G22";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" I", i);
        text += appendIfNotNull(" J", j);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G23(){
        write("G23");
    }

    void G28(double x, double y, double z){
        std::string text = "";
        text += "G28";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        write(text);
    }

    void G29(double x, double y, double z){
        std::string text = "";
        text += "G29";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        write(text);
    }

    void G30(int p, double x, double y, double z){
        std::string text = "";
        text += "G30";
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        write(text);
    }

    void G31(double x, double y, double z, double f, double q, double p){
        std::string text = "";
        text += "G31";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" Q", q);
        text += appendIfNotNull(" P", p);
        write(text);
    }

    void G33(double z, double f){
        std::string text = "";
        text += "G33";
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G372(int k, double z, double r, double f, double p,double q){
        std::string text = "";
        text += "G37.2";
        text += appendIfNotNull(" K", k);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" Q", q);
        write(text);
    }

    void G74(double x, double y, double z, double r, double p, double q, double f, double e, double k) {
        std::string text = "G74";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" Q", q);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" E", e);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G76(double x, double y, double z, double r, double q, double p, double f, double k) {
        std::string text = "G76";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" Q", q);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G80() {
        std::string text = "G80";
        write(text);
    }

    void G81(double x, double y, double z, double r, double f, double f2, double k, double q, double d) {
        std::string text = "G81";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" F2=", f);
        text += appendIfNotNull(" K", k);
        text += appendIfNotNull(" Q", q);
        text += appendIfNotNull(" D", d);
        write(text);
    }

    void G81_1(double z, double q, double r, double f) {
        std::string text = "G81.1";
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" Q", q);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G82(double x, double y, double z, double r, double p, double f, double k) {
        std::string text = "G82";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G83(double x, double y, double z, double r, double q, double f, double k) {
        std::string text = "G83";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" Q", q);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G84(double x, double y, double z, double r, double p, double q, double f, double e, double k) {
        std::string text = "G84";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" Q", q);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" E", e);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G85(double x, double y, double z, double r, double f, double k) {
        std::string text = "G85";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G86(double x, double y, double z, double r, double f, double k) {
        std::string text = "G86";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G87(double x, double y, double z, double r, double q, double p, double f, double e, double k) {
        std::string text = "G87";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" Q", q);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" E", e);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G88(double x, double y, double z, double r, double p, double f, double k) {
        std::string text = "G88";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G89(double x, double y, double z, double r, double p, double f, double k) {
        std::string text = "G89";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" R", r);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" F", f);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G90() {
        std::string text = "G90";
        write(text);
    }

    void G91() {
        std::string text = "G91";
        write(text);
    }

    void G92(double x, double y, double z) {
        std::string text = "G92";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        write(text);
    }

    void G92_1(double x, double y, double z, double i, double j, double k, double r) {
        std::string text = "G89";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" Z", z);
        text += appendIfNotNull(" I", i);
        text += appendIfNotNull(" J", j);
        text += appendIfNotNull(" K", k);
        text += appendIfNotNull(" R", r);
        write(text);
    }

    void G93() {
        std::string text = "G93";
        write(text);
    }

    void G94(double f) {
        std::string text = "G94";
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G95(double f) {
        std::string text = "G95";
        text += appendIfNotNull(" F", f);
        write(text);
    }

    void G96(double s) {
        std::string text = "G96";
        text += appendIfNotNull(" S", s);
        write(text);
    }

    void G97(double s) {
        std::string text = "G97";
        text += appendIfNotNull(" S", s);
        write(text);
    }

    void G120_1(double p, double q) {
        std::string text = "G120.1";
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" Q", q);
        write(text);
    }

    void G134(double x, double y, double i, double j, double k) {
        std::string text = "G134";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" I", i);
        text += appendIfNotNull(" J", j);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G135(double x, double y, double i, double j, double k) {
        std::string text = "G135";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" I", i);
        text += appendIfNotNull(" J", j);
        text += appendIfNotNull(" K", k);
        write(text);
    }
    void G136(double x, double y, double i, double j, double p, double k) {
        std::string text = "G136";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" I", i);
        text += appendIfNotNull(" J", j);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" K", k);
        write(text);
    }

    void G137_1(double x, double y, double i, double p, double j, double k) {
        std::string text = "G136";
        text += appendIfNotNull(" X", x);
        text += appendIfNotNull(" Y", y);
        text += appendIfNotNull(" I", i);
        text += appendIfNotNull(" P", p);
        text += appendIfNotNull(" J", j);
        text += appendIfNotNull(" K", k);
        write(text);
    }

}

#endif //GCODE_GCODE_H
