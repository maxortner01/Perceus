#pragma once

#include <iostream>
#include "Vector.h"

namespace pcs
{
    template<typename T, int R, int C>
    struct Matrix
    {
        T m[R][C];

        void toIdentity()
        {
            if (C != R) return;

            for (int i = 0; i < R; i++)
            {
                m[i][i] = 1;
            }
        }

        static Matrix<T, R, C> makeTranslation(const Vec3f &vec)
        {
            Matrix<T, R, C> mat = Matrix<T, R, C>();
            mat.toIdentity();

            mat.m[0][C - 1] = vec.x;
            mat.m[1][C - 1] = vec.y;
            mat.m[2][C - 1] = vec.z;

            return mat;
        }

        Vec4f getRow(int index)
        {
            return Vec4f(m[index][0], m[index][1], m[index][2], m[index][3]);
        }

        Matrix<T, R, C> operator*(const Matrix<T, R, C> &mat) const
        {
            Matrix<T, R, C> res = Matrix<T, R, C>();

            for (int i = 0; i < R; i++)
                for (int j = 0; j < R; j++)
                {
                    res.m[i][j] = 0;
                    for (int k = 0; k < R; k++)
                        res.m[i][j] += m[i][k] * mat.m[k][j];
                }

            return res;
        }

        void print() const
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    std::cout << m[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
    };

    typedef Matrix<float, 4, 4> Mat4f;
}