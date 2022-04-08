#pragma once
#include <iostream>
#include <vector>

using namespace std;
namespace fun {
    class IGeoFig {
    public:
        virtual double square() = 0;
        virtual double perimeter() = 0;
    };

    class CVector2D {
    public:
        double x;
        double y;
        CVector2D() = default;
        friend istream& operator>> (istream&, CVector2D&);
        friend ostream& operator<< (ostream&, const CVector2D&);
    };

    class IPhysObject {
    public:
        virtual double mass() const = 0;
        virtual CVector2D position() = 0;
        virtual bool operator== (const IPhysObject& ob) const = 0;
        virtual bool operator< (const IPhysObject& ob) const = 0;
    };

    class IPrintable {
    public:
        virtual void draw() = 0;
    };

    class IDialogInitable {
    public:
        virtual void initFromDialog() = 0;
    };

    class BaseCObject {
    public:
        virtual const char* classname() = 0;
        virtual unsigned int size() = 0;
    };

    class G_Figure :
        public IGeoFig,
        public CVector2D,
        public IPhysObject,
        public IPrintable,
        public IDialogInitable,
        public BaseCObject {};

    class Circle : G_Figure {
    private:
        double x, y;
        double rad;
        double m;
    public:
        Circle();
        void initFromDialog() override;
        double square() override;
        double perimeter() override;
        double mass() const override;
        CVector2D position() override;
        bool operator == (const IPhysObject& obj) const override;
        bool operator < (const IPhysObject& obj) const override;
        void draw() override;
        const char* classname() override;
        unsigned int size() override;
    };
    class Rectangle : G_Figure {
    private:
        double x, y;
        double f_edge, s_edge;
        double m;
    public:
        Rectangle();
        void initFromDialog() override;
        double square() override;
        double perimeter() override;
        double mass() const override;
        CVector2D position() override;
        bool operator == (const IPhysObject& obj) const override;
        bool operator < (const IPhysObject& obj) const override;
        void draw() override;
        const char* classname() override;
        unsigned int size() override;
    };
    class Menu {
    private:
        char command='-';
        vector<G_Figure*> figures;
        double sum_perim = 0;
        double sum_sq = 0;
        double sum_m = 0;
        unsigned int sum_size = 0;
    public:
        Menu();
        void action();
        template<class Figure>
        void createFigure() {
            auto* figure = new Figure();
            figure->initFromDialog();
            sum_sq += figure->square();
            sum_perim += figure->perimeter();
            sum_m += figure->mass();
            sum_size += figure->size();
            figures.push_back((G_Figure*)figure);
        }
        void Menu_action();
        void active();
    };
};