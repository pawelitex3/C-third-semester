#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Figure{
    public:
        virtual bool in_figure(double x, double y)=0;
        virtual void input()=0;
};

class Rectangle:public Figure{
    private:
        double  left_upper_x, left_upper_y,
                right_lower_x, right_lower_y;
    public:
        virtual bool in_figure(double x, double y);
        virtual void input();

};

class Circle:public Figure{
    private:
        double  center_x, center_y, radius;
    public:
        virtual bool in_figure(double x, double y);
        virtual void input();

};

class Triangle:public Figure{
    private:
        double  x1, y1,
                x2, y2,
                x3, y3;
    public:
        virtual bool in_figure(double x, double y);
        virtual void input();

};

void Rectangle::input()
{
    cin>>this->left_upper_x>>this->left_upper_y>>this->right_lower_x>>this->right_lower_y;
}

void Circle::input()
{
    cin>>this->center_x>>this->center_y>>this->radius;
}

void Triangle::input()
{
    cin>>this->x1>>this->y1>>this->x2>>this->y2>>this->x3>>this->y3;
}

bool Rectangle::in_figure(double x, double y)
{
    bool inside=true;
    if(this->left_upper_y > this->right_lower_y && this->left_upper_x < this->right_lower_x){
        if(x<=this->left_upper_x) inside=false;
        if(x>=this->right_lower_x) inside=false;
        if(y>=this->left_upper_y) inside=false;
        if(y<=this->right_lower_y) inside=false;
    }
    else{
        if(x<=this->left_upper_x) inside=false;
        if(x>=this->right_lower_x) inside=false;
        if(y<=this->left_upper_y) inside=false;
        if(y>=this->right_lower_y) inside=false;
    }
    return inside;
}

bool Circle::in_figure(double x, double y)
{
    double distance;
    distance = sqrt((x-this->center_x) * (x-this->center_x) + (y-this->center_y) * (y-this->center_y));
    return distance<this->radius;
}

bool Triangle::in_figure(double x, double y)
{
    ///Prosta P
    double Ap, Bp, Cp, valueP;
    Ap = this->y2 - this->y1;
    Bp = -(this->x2 - this->x1);
    Cp = (this->y1 * this->x2 - this->x1 * this->y2);
    valueP = (Ap*x + Bp*y + Cp) * (Ap*this->x3 + Bp*this->y3 + Cp);
    ///Prosta Q
    double Aq, Bq, Cq, valueQ;
    Aq = this->y3 - this->y2;
    Bq = -(this->x3 - this->x2);
    Cq = (this->y2 * this->x3 - this->x2 * this->y3);
    valueQ = (Aq*this->x1 + Bq*this->y1 + Cq) * (Aq*x + Bq*y + Cq);
    ///Prosta K
    double Ak, Bk, Ck, valueK;
    Ak = this->y3 - this->y1;
    Bk = -(this->x3 - this->x1);
    Ck = (this->y1 * this->x3 - this->x1 * this->y3);
    valueK = (Ak*this->x2 + Bk*this->y2 + Ck) * (Ak*x + Bk*y + Ck);

    if(valueK >0 && valueP >0 && valueQ>0) return true;
    else return false;

}

int main()
{
    vector <Figure *> figures;
    char type;
    double x, y;
    int i, licznik, number_of_point;
    cin>>type;
    while(type!='*'){
        if(type == 'r'){
            Figure *f = new Rectangle;
            f->input();
            figures.push_back(f);
        }
        else if(type == 'c'){
            Figure *f = new Circle;
            f->input();
            figures.push_back(f);
        }
        else if(type == 't'){
            Figure *f = new Triangle;
            f->input();
            figures.push_back(f);
        }
        cin>>type;
    }

    cin>>x>>y;
    number_of_point=1;
    while(x!=9999.9 || y!=9999.9){
        licznik=0;
        for(i=0; i<figures.size(); i++){
            if(figures[i]->in_figure(x, y)){
                cout<<"Point "<<number_of_point<<" is contained in figure "<<i+1<<endl;
                licznik++;
            }
        }
        if(licznik == 0){
            cout<<"Point "<<number_of_point<<" is not contained in any figure"<<endl;
        }
        number_of_point++;
        cin>>x>>y;
    }




    return 0;
}
