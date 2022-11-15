#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>

template<typename Type>
class complex{
    public:
        using value_type = Type;

        value_type re() const {return re_;}
        value_type im() const {return im_;}

        complex()
            : re_(0)
            , im_(0) {}
        
        complex(value_type re)
            : re_(re)
            , im_(0) {}

        complex(value_type re, value_type im)
            : re_(re)
            , im_(im) {}
        
        complex& operator += (const complex& other){
            re_ += other.re_;
            im_ += other.im_;
            return *this;
        }

        complex& operator *= (const complex& other){
            value_type re = re_*other.re_ - im_*other.im_;
            im_ = re_*other.im_ + im_*other.re_;
            re_ = re;
            return *this;
        }

        complex& operator -= (const complex& other){
            re_ -= other.re_;
            im_ -= other.im_;
            return *this;
        }

        complex& operator /= (const complex& other){
            value_type re = re_*other.re_ + im_*other.im_;
            value_type mod = other.re_*other.re_ + other.im_*other.im_;
            im_ = (re_*other.im_ - im_*other.re_)/mod; 
            re_ = re/mod;
            return *this;
        }

        complex operator - () const{
            return complex(-re_,-im_);
        }

        complex operator ~ () const{
            return complex(re_,-im_);
        }

    private:
        value_type re_;
        value_type im_;
};

#include "functions.h"

#endif
