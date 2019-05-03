#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

class Matrix3D
{
public:
    double** m;
// n
    Matrix3D(){
        m = new double* [3];

        for (int i = 0; i < 3; i++)
            m[i] = new double [3];

        printf("CTOR\n");
    }

//
    ~Matrix3D(){
        for (int i = 0; i < 3; i++)
            delete [] m[i];
        delete[] m;}

    Matrix3D operator- (const Matrix3D& v){
        Matrix3D res;
        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                res.m[i][j]=m[i][j]-v.m[i][j];
        return res;
    }
// + ,
//
    Matrix3D operator+ (const Matrix3D& v){
        Matrix3D res;
        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                res.m[i][j]=v.m[i][j]+m[i][j];

        return res;
    }
    /*Matrix3D operator* (const Matrix3D v){
        Matrix3D res;
        for (unsigned int j = 0; i < 3; j++){
            for (unsigned int i = 0; i < 3; i++)
                res.m[j][i]=v.m[j][i]+m[i][j];}
        return res;
    }*/
    Matrix3D operator* (const Matrix3D& v){
        Matrix3D res;
        for (unsigned int j = 0; j < 3; j++){
            for (unsigned int i = 0; i < 3; i++)
                res.m[j][i]+=v.m[j][i]*m[i][j];}
        return res;
    }
    Matrix3D operator* (double a) const {
        Matrix3D res;

        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                res.m[i][j] = m[i][j] * a;
            
        return res;

    }

    /*
    double det(){
        return ( m[1][1]*m[2][2]*m[3][3]+m[2][1]*m[3][2]*m[1][3]+m[1][2]*m[2][3]*m[3][1]-m[3][1]*m[2][2]*m[1][3]-m[2][1]*m[1][2]*m[3][3]-m[3][2]*m[2][3]*m[1][1]);
    }*/

    void setValue(unsigned int i, unsigned int j, double value){
        m[i][j]=value;
    }

    double getValue(unsigned int i, unsigned int j) const{
        return m[i][j];
    }
};
Matrix3D operator* (int a, const Matrix3D& v){
    return v * a;
}


class Vector3D
{
public:

    double* m;
// n
    Vector3D(){
        m=new double[3];
    }

//
    ~Vector3D(){
        delete[] m;}

//
    double getValue(unsigned int i) const{
        return m[i];
    }

// i- value,
// i 0 n-1
    void setValue(unsigned int i, double value){
        m[i]=value;
    }
//

/*
*
*/

// == ,
// скалярное произв
    double operator* (const Vector3D& v) {
        double resk=0;
        for (unsigned int i = 0; i < 3; i++ )
           resk += v.m[i]*m[i];
        return resk;
    }

// != ,
// ,
    Vector3D operator- (const Vector3D& v){
        Vector3D res;
        for (unsigned int i = 0; i < 3; i++)
            res.m[i]=m[i]-v.m[i];
        return res;
    }
// + ,
//
    Vector3D operator+ (const Vector3D& v){
        Vector3D res;
        for (unsigned int i = 0; i < 3; i++)
            res.m[i]=v.m[i]+m[i];
        return res;
    }

    Vector3D operator* (double a) const {
        Vector3D res;
        for (unsigned int i = 0; i < 3; i++)
            res.m[i] = m[i] * a;
        return res;

    }
    Vector3D operator* (const Matrix3D& b) const {
        Vector3D res;
        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                res.m[i]+= b.m[j][i]*m[j];
        return res;
    }
};
Vector3D operator* (double a, const Vector3D& v){
    return v * a;
}



int main()
{
    Vector3D a;
    a.setValue(0, 0);
    a.setValue(1, 1.5);
    a.setValue(2, 2);

    Vector3D b;
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);


    Vector3D c = a + b;
    Vector3D d = a * 5;
    Vector3D e = a - b;
    float sk = a * b;

    for(unsigned int i = 0; i < 3; ++i)
        cout << c.getValue(i) << endl;
    cout<<endl;

    for(unsigned int i = 0; i < 3; ++i)
        cout << d.getValue(i) << endl;
    cout<<endl;

    for(unsigned int i = 0; i < 3; ++i)
        cout << e.getValue(i) << endl;
    cout<<endl;

    cout<<sk<<endl;


    Matrix3D x;
    x.setValue(0, 0, 1);
    x.setValue(0, 1, 4);
    x.setValue(0, 2, 2);
    x.setValue(1, 0, 1);
    x.setValue(1, 1, 0);
    x.setValue(1, 2, 2);
    x.setValue(2, 0, 1);
    x.setValue(2, 1, 6);
    x.setValue(2, 2, 2);


    Matrix3D y;
    y.setValue(0, 0, 1);
    y.setValue(0, 1, 0);
    y.setValue(0, 2, 1.5);
    y.setValue(1, 0, 2);
    y.setValue(1, 1, 1);
    y.setValue(1, 2, 1);
    y.setValue(2, 0, 0);
    y.setValue(2, 1, 1.5);
    y.setValue(2, 2, 2);


    printf("x\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << (x.m[i][j]) << " ";
        cout<<endl;
    }
    cout<<endl;

    printf("y\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << (y.m[i][j]) << " ";
        cout<<endl;
    }
    cout<<endl;


    Matrix3D q = x + y;
    Matrix3D w = x - y;
    //Matrix3D i = x * y;
    Vector3D o = a * x;
    Matrix3D u = y * 2;

    printf("+\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << q.getValue(i,j) << " ";
        cout<<endl;
    }
    cout<<endl;


    printf("-\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << w.getValue(i,j) << " ";
        cout<<endl;
    }
    cout<<endl;

    
    for(unsigned int i = 0; i < 3; ++i)
        cout << o.getValue(i) << " ";
    cout<<endl;

    printf("*2\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << u.getValue(i,j) << " ";
        cout<<endl;
    }
    cout<<endl;


    printf("x\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << (x.m[i][j]) << " ";
        cout<<endl;
    }
    cout<<endl;

    printf("y\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << (y.m[i][j]) << " ";
        cout<<endl;
    }
    cout<<endl;

}
