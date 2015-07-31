#include <layer/math.h>
#include "python.h"

void python_export_math(py::module &m) {
    /* math.h bindings */
    py::module math = m.def_submodule("math", "Mathematical routines, special functions, etc.");

    math.def("signum",          (double(*)(double))                           math::signum, D(math, signum));
    math.def("safe_acos",       (double(*)(double))                           math::safe_acos, D(math, safe_acos));
    math.def("safe_asin",       (double(*)(double))                           math::safe_asin, D(math, safe_asin));
    math.def("safe_sqrt",       (double(*)(double))                           math::safe_sqrt, D(math, safe_sqrt));
    math.def("erf",             (double(*)(double))                           math::erf, D(math, erf));
    math.def("erfinv",          (double(*)(double))                           math::erfinv, D(math, erfinv));
    math.def("normal_quantile", (double(*)(double))                           math::normal_quantile, D(math, normal_quantile));
    math.def("normal_cdf",      (double(*)(double))                           math::normal_cdf, D(math, normal_cdf));
    math.def("comp_ellint_1",   (double(*)(double))                           math::comp_ellint_1, D(math, comp_ellint_1));
    math.def("comp_ellint_2",   (double(*)(double))                           math::comp_ellint_2, D(math, comp_ellint_2));
    math.def("comp_ellint_3",   (double(*)(double, double))                   math::comp_ellint_3, D(math, comp_ellint_3));
    math.def("ellint_1",        (double(*)(double, double))                   math::ellint_1, D(math, ellint_1));
    math.def("ellint_2",        (double(*)(double, double))                   math::ellint_2, D(math, ellint_2));
    math.def("ellint_3",        (double(*)(double, double, double))           math::ellint_3, D(math, ellint_3));
    math.def("i0e",             (double(*)(double))                           math::i0e, D(math, i0e));
    math.def("legendre_p",      (double(*)(int l, double))                    math::legendre_p, D(math, legendre_p));
    math.def("legendre_p",      (double(*)(int, int, double))                 math::legendre_p, D(math, legendre_p, 2));
    math.def("legendre_pd",     (std::pair<double, double>(*)(int l, double)) math::legendre_pd, D(math, legendre_pd));

    math.attr("E")               = py::cast(math::E_d);
    math.attr("Pi")              = py::cast(math::Pi_d);
    math.attr("InvPi")           = py::cast(math::InvPi_d);
    math.attr("InvTwoPi")        = py::cast(math::InvTwoPi_d);
    math.attr("InvFourPi")       = py::cast(math::InvFourPi_d);
    math.attr("SqrtPi")          = py::cast(math::SqrtPi_d);
    math.attr("InvSqrtPi")       = py::cast(math::InvSqrtPi_d);
    math.attr("SqrtTwo")         = py::cast(math::SqrtTwo_d);
    math.attr("InvSqrtTwo")      = py::cast(math::InvSqrtTwo_d);
    math.attr("SqrtTwoPi")       = py::cast(math::SqrtTwoPi_d);
    math.attr("InvSqrtTwoPi")    = py::cast(math::InvSqrtTwoPi_d);
    math.attr("OneMinusEpsilon") = py::cast(math::OneMinusEpsilon);
    math.attr("RecipOverflow")   = py::cast(math::RecipOverflow);

    math.def("findInterval", [](size_t size, py::function pred) {
        return math::findInterval(size, [&](size_t i) { return pred.call(i).cast<bool>(); });
    }, D(math, findInterval));
}
