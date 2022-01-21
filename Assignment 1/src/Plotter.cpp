#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    int flag=0;
    double x0=0,y0=0,x1,y1;
    PenStyle pen={1,"black"};
    for(string line;getline(input,line);){
        line=toLowerCase(line);
        Vector<string> spline=stringSplit(line," ");
        if(startsWith(line,"penup")){
            flag=0;
        }
        else if(startsWith(line,"pendown")){
            flag=1;
        }
        else if(startsWith(line,"moveabs")){
            x1=stringToReal(spline[1]);
            y1=stringToReal(spline[2]);
            if(flag)
                drawLine(x0,y0,x1,y1,pen);
            x0=x1;
            y0=y1;
        }
        else if(startsWith(line,"moverel")){
            x1=x0+stringToReal(spline[1]);
            y1=y0+stringToReal(spline[2]);
            if(flag)
                drawLine(x0,y0,x1,y1,pen);
            x0=x1;
            y0=y1;
        }
        else if (startsWith(line,"penwidth")) {
            pen.width=stringToReal(spline[1]);
        }
        else if(startsWith(line,"pencolor"))
            pen.color=spline[1];
    }
}
