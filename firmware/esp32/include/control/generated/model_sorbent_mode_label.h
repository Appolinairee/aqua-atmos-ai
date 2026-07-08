#pragma once

#include "control/generated/model_utils.h"

#include <string.h>


inline void predict_sorbent_mode_label(const double * input, double * output) {
    double var0[3];
    double var1[3];
    double var2[3];
    double var3[3];
    double var4[3];
    double var5[3];
    double var6[3];
    double var7[3];
    double var8[3];
    double var9[3];
    double var10[3];
    double var11[3];
    double var12[3];
    double var13[3];
    double var14[3];
    double var15[3];
    double var16[3];
    double var17[3];
    double var18[3];
    double var19[3];
    double var20[3];
    if (input[5] <= 37.08500099182129) {
        if (input[16] <= 3.2450000047683716) {
            if (input[9] <= 19.998287200927734) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[8] <= 94.98080444335938) {
                    if (input[15] <= 0.9919434785842896) {
                        if (input[9] <= 44.493852615356445) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.9411764705882353, 0.058823529411764705}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 26.510000228881836) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                }
            }
        } else {
            if (input[8] <= 94.99926376342773) {
                if (input[16] <= 3.6149998903274536) {
                    if (input[5] <= 28.22000026702881) {
                        if (input[11] <= 10.102756977081299) {
                            { double _tmp[] = {0.14285714285714285, 0.42857142857142855, 0.42857142857142855}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[0] <= 12.5) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6956521739130435, 0.30434782608695654, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[3] <= 276.13500213623047) {
                        if (input[16] <= 4.769999980926514) {
                            { double _tmp[] = {0.0, 0.9230769230769231, 0.07692307692307693}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= 0.17683805525302887) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.0, 0.5}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
            }
        }
    } else {
        if (input[4] <= 13.394999980926514) {
            if (input[12] <= -0.379409521818161) {
                if (input[6] <= 29.86500072479248) {
                    if (input[8] <= 95.0388298034668) {
                        if (input[6] <= 25.824999809265137) {
                            { double _tmp[] = {0.2586206896551724, 0.7155172413793103, 0.025862068965517234}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4758364312267658, 0.5241635687732342, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[16] <= 3.590000033378601) {
                        if (input[17] <= 10.480000019073486) {
                            { double _tmp[] = {0.7716049382716049, 0.22839506172839505, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                if (input[9] <= 20.068947792053223) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[7] <= 0.4799999874085188) {
                        if (input[1] <= 23.295000076293945) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[21] <= 0.5) {
                if (input[2] <= 57.84499931335449) {
                    if (input[9] <= 20.02723979949951) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[11] <= 12.457056045532227) {
                            { double _tmp[] = {0.0, 0.007518796992481203, 0.9924812030075187}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.2835820895522388, 0.7164179104477612}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.1980562210083) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[10] <= 18.112985610961914) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.06666666666666667, 0.9333333333333333}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 20.002090454101562) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[15] <= 0.6838940978050232) {
                        if (input[8] <= 94.99361419677734) {
                            { double _tmp[] = {0.0, 0.24528301886792453, 0.7547169811320755}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var20, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        }
    }
    double var21[3];
    if (input[2] <= 61.385000228881836) {
        if (input[8] <= 94.99821853637695) {
            if (input[4] <= 13.424999713897705) {
                if (input[9] <= 20.00054359436035) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[10] <= 13.743006229400635) {
                        if (input[6] <= 24.864999771118164) {
                            { double _tmp[] = {0.2413793103448276, 0.7241379310344828, 0.034482758620689655}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 39.09719276428223) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.3333333333333333, 0.6666666666666666}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[6] <= 22.43000030517578) {
                    if (input[9] <= 20.147778511047363) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[16] <= 4.420000076293945) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.25, 0.75}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[12] <= 0.12940952181816107) {
                        if (input[10] <= 17.362319946289062) {
                            { double _tmp[] = {0.1977401129943503, 0.01694915254237288, 0.7853107344632768}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3473053892215569, 0.1497005988023952, 0.5029940119760479}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 92.69633102416992) {
                            { double _tmp[] = {0.9636363636363636, 0.0, 0.03636363636363636}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
        }
    } else {
        if (input[20] <= 0.5) {
            if (input[9] <= 25.91197681427002) {
                { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[19] <= 0.5) {
                    if (input[14] <= 0.5197004973888397) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[0] <= 7.5) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9156626506024097, 0.06024096385542169, 0.02409638554216868}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 2.7699999809265137) {
                        if (input[7] <= 0.8849999904632568) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2, 0.8, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= -0.8520459532737732) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.893491124260355, 0.10650887573964497, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[9] <= 20.004352569580078) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[10] <= 20.279298782348633) {
                    if (input[12] <= -0.9829629063606262) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[4] <= 8.045000076293945) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.1875, 0.3125, 0.5}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[6] <= 28.130000114440918) {
                        if (input[9] <= 21.51754856109619) {
                            { double _tmp[] = {0.0, 0.9, 0.1}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.18181818181818182, 0.8181818181818182}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var21, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var20, var21, 3, var19);
    double var22[3];
    if (input[5] <= 37.44000053405762) {
        if (input[2] <= 55.79999923706055) {
            if (input[1] <= 27.260000228881836) {
                if (input[9] <= 19.990093231201172) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[1] <= 25.6200008392334) {
                            { double _tmp[] = {0.375, 0.625, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9545454545454546, 0.045454545454545456, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 22.03972816467285) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 19.954151153564453) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[8] <= 94.54814910888672) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[20] <= 0.5) {
                if (input[8] <= 95.00268173217773) {
                    if (input[7] <= 1.0450000166893005) {
                        if (input[9] <= 34.242788314819336) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                }
            } else {
                if (input[1] <= 32.209999084472656) {
                    if (input[1] <= 27.030000686645508) {
                        if (input[12] <= 0.7865660786628723) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9957591178965225, 0.004240882103477523, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 13.547248840332031) {
                            { double _tmp[] = {0.5882352941176471, 0.4117647058823529, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9774305555555556, 0.022569444444444444, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 23.94046688079834) {
                        if (input[11] <= 18.273548126220703) {
                            { double _tmp[] = {0.8, 0.2, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.14285714285714285, 0.8571428571428571, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= -0.9241537749767303) {
                            { double _tmp[] = {0.5555555555555556, 0.4444444444444444, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9125, 0.0875, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[9] <= 20.00054359436035) {
            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
        } else {
            if (input[4] <= 13.400000095367432) {
                if (input[15] <= 0.5343527793884277) {
                    if (input[14] <= 0.9955121576786041) {
                        if (input[16] <= 4.130000114440918) {
                            { double _tmp[] = {0.04741379310344827, 0.9525862068965517, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.0, 0.3333333333333333}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.6363636363636364, 0.0, 0.36363636363636365}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[15] <= 0.6963504254817963) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[2] <= 39.920000076293945) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 94.99361419677734) {
                    if (input[2] <= 50.89500045776367) {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[9] <= 20.393335342407227) {
                            { double _tmp[] = {0.0, 0.8333333333333334, 0.16666666666666666}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.18633540372670807, 0.8136645962732919}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var22, _tmp, 3 * sizeof(double)); }
                }
            }
        }
    }
    add_vectors(var19, var22, 3, var18);
    double var23[3];
    if (input[2] <= 62.885000228881836) {
        if (input[0] <= 16.5) {
            if (input[0] <= 13.5) {
                if (input[9] <= 20.011646270751953) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[21] <= 0.5) {
                        if (input[7] <= 0.9650000035762787) {
                            { double _tmp[] = {0.0, 0.12179487179487179, 0.8782051282051282}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[12] <= 0.12940952181816107) {
                            { double _tmp[] = {0.47560975609756095, 0.012195121951219513, 0.5121951219512195}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8571428571428572, 0.07142857142857144, 0.07142857142857144}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 20.00141429901123) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[9] <= 25.966920852661133) {
                        if (input[12] <= -0.6035533845424652) {
                            { double _tmp[] = {0.0391304347826087, 0.9608695652173913, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.026490066225165563, 0.6026490066225165, 0.3708609271523179}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 95.06427383422852) {
                            { double _tmp[] = {0.375, 0.375, 0.25}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[9] <= 19.990134239196777) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[8] <= 94.99171447753906) {
                    if (input[2] <= 41.154998779296875) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[17] <= -0.29500000178813934) {
                            { double _tmp[] = {0.0, 0.8666666666666667, 0.13333333333333333}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[4] <= 14.900000095367432) {
            if (input[20] <= 0.5) {
                if (input[8] <= 94.99251556396484) {
                    if (input[7] <= 0.8849999904632568) {
                        if (input[13] <= 0.12940952181816104) {
                            { double _tmp[] = {0.0, 0.625, 0.375}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                }
            } else {
                if (input[6] <= 28.149999618530273) {
                    if (input[9] <= 20.972272872924805) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[6] <= 22.375) {
                            { double _tmp[] = {0.7333333333333333, 0.26666666666666666, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.5, 0.5}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 23.200611114501953) {
                        if (input[9] <= 20.003310203552246) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.111882209777832) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[3] <= 612.3349914550781) {
                { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
            } else {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var23, _tmp, 3 * sizeof(double)); }
            }
        }
    }
    add_vectors(var18, var23, 3, var17);
    double var24[3];
    if (input[5] <= 42.875) {
        if (input[3] <= 106.88999938964844) {
            if (input[16] <= 3.2549999952316284) {
                if (input[13] <= -0.00000000000000006123233601181349) {
                    if (input[11] <= 9.135581970214844) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[11] <= 14.06960678100586) {
                            { double _tmp[] = {0.8648648648648649, 0.13513513513513514, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9737991266375546, 0.026200873362445413, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 9.142839431762695) {
                        if (input[0] <= 5.5) {
                            { double _tmp[] = {0.9705882352941176, 0.029411764705882353, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7352941176470589, 0.2647058823529412, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 6.065000057220459) {
                            { double _tmp[] = {0.9890988372093024, 0.010174418604651164, 0.0007267441860465116}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5714285714285714, 0.42857142857142855, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 94.99011611938477) {
                    if (input[20] <= 0.5) {
                        if (input[5] <= 27.22000026702881) {
                            { double _tmp[] = {0.0, 0.9473684210526315, 0.05263157894736842}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                }
            }
        } else {
            if (input[9] <= 20.00141429901123) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[0] <= 14.5) {
                    if (input[8] <= 94.98282623291016) {
                        if (input[4] <= 11.309999942779541) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.18181818181818182, 0.8181818181818182}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[14] <= 0.5270728468894958) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.016260162601626018, 0.983739837398374, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 94.92838668823242) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[9] <= 20.007081031799316) {
            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
        } else {
            if (input[3] <= 499.9549865722656) {
                if (input[17] <= 14.820000171661377) {
                    if (input[10] <= 16.424657821655273) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[21] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                if (input[21] <= 0.5) {
                    if (input[15] <= 0.3975280821323395) {
                        if (input[16] <= 3.40500009059906) {
                            { double _tmp[] = {0.0, 0.475, 0.525}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.11764705882352941, 0.8823529411764706}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 50.0049991607666) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.04, 0.96}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[17] <= 16.15999984741211) {
                            { double _tmp[] = {0.16666666666666666, 0.5, 0.3333333333333333}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9272727272727272, 0.01818181818181818, 0.05454545454545454}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[12] <= 0.12940952181816107) {
                            { double _tmp[] = {0.06896551724137931, 0.10344827586206896, 0.8275862068965517}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var24, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var17, var24, 3, var16);
    double var25[3];
    if (input[19] <= 0.5) {
        if (input[5] <= 44.010000228881836) {
            if (input[9] <= 19.993428230285645) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[6] <= 24.190000534057617) {
                    if (input[8] <= 94.98890686035156) {
                        if (input[3] <= 502.61500549316406) {
                            { double _tmp[] = {0.017857142857142856, 0.8928571428571429, 0.08928571428571429}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.09090909090909091, 0.9090909090909091}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[16] <= 4.085000038146973) {
                        if (input[1] <= 30.350000381469727) {
                            { double _tmp[] = {0.24186046511627907, 0.7395348837209302, 0.018604651162790697}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 11.85511589050293) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[10] <= 21.146190643310547) {
                if (input[7] <= 0.949999988079071) {
                    if (input[12] <= 0.12940952181816107) {
                        if (input[4] <= 13.434999942779541) {
                            { double _tmp[] = {0.3157894736842105, 0.6842105263157895, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.40498442367601245, 0.0, 0.5950155763239875}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 12.212264060974121) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.775, 0.0, 0.225}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 15.07279634475708) {
                        if (input[15] <= -0.3896160125732422) {
                            { double _tmp[] = {0.9166666666666666, 0.08333333333333333, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.36363636363636365, 0.6363636363636364, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[3] <= 471.1300048828125) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 19.98351001739502) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[1] <= 32.11999988555908) {
                        if (input[14] <= 0.6870273351669312) {
                            { double _tmp[] = {0.0, 0.7575757575757576, 0.24242424242424243}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.18181818181818182, 0.8181818181818182}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[9] <= 22.628232955932617) {
            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
        } else {
            if (input[8] <= 94.98286056518555) {
                if (input[7] <= 0.7600000202655792) {
                    if (input[17] <= 0.34999999962747097) {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var25, _tmp, 3 * sizeof(double)); }
            }
        }
    }
    add_vectors(var16, var25, 3, var15);
    double var26[3];
    if (input[4] <= 13.440000057220459) {
        if (input[13] <= -0.00000000000000006123233601181349) {
            if (input[6] <= 23.035000801086426) {
                if (input[3] <= 45.060001373291016) {
                    if (input[15] <= 0.889639139175415) {
                        if (input[10] <= 15.6088285446167) {
                            { double _tmp[] = {0.3333333333333333, 0.3333333333333333, 0.3333333333333333}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[8] <= 94.62129592895508) {
                        if (input[9] <= 19.994850158691406) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 16.704999923706055) {
                            { double _tmp[] = {0.5238095238095238, 0.38095238095238093, 0.09523809523809523}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[11] <= 13.645792961120605) {
                    if (input[3] <= 283.8450012207031) {
                        if (input[10] <= 18.76724147796631) {
                            { double _tmp[] = {0.8243243243243243, 0.16666666666666666, 0.009009009009009009}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2, 0.8, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 40.005001068115234) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.46285714285714286, 0.5142857142857142, 0.022857142857142857}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.003056526184082) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[8] <= 94.98330688476562) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[2] <= 44.69000053405762) {
                { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[14] <= 0.999657392501831) {
                    if (input[20] <= 0.5) {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.0, 0.9152542372881356, 0.0847457627118644}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9441860465116279, 0.05581395348837209, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= -0.8949999809265137) {
                            { double _tmp[] = {0.993421052631579, 0.006578947368421052, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9996159754224271, 0.00038402457757296467, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[1] <= 20.13499927520752) {
                        if (input[9] <= 25.7869930267334) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.8571428571428571, 0.14285714285714285}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[12] <= -0.12940952181816096) {
            if (input[8] <= 94.96247482299805) {
                if (input[13] <= -0.9159756004810333) {
                    if (input[11] <= 9.652748584747314) {
                        if (input[9] <= 19.814688682556152) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.925000011920929) {
                            { double _tmp[] = {0.13861386138613863, 0.0, 0.8613861386138614}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 1.024999976158142) {
                        if (input[16] <= 3.3549998998641968) {
                            { double _tmp[] = {0.6956521739130435, 0.0, 0.30434782608695654}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.22033898305084745, 0.0, 0.7796610169491526}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
            }
        } else {
            if (input[9] <= 20.020448684692383) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[14] <= 0.523396223783493) {
                    { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[14] <= 0.998842716217041) {
                            { double _tmp[] = {0.8846153846153846, 0.019230769230769232, 0.09615384615384616}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 1.0550000071525574) {
                            { double _tmp[] = {0.0425531914893617, 0.0, 0.9574468085106383}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var26, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var15, var26, 3, var14);
    double var27[3];
    if (input[2] <= 61.90500068664551) {
        if (input[13] <= -0.7865660786628723) {
            if (input[0] <= 11.5) {
                if (input[16] <= 3.375) {
                    if (input[8] <= 93.63417053222656) {
                        if (input[10] <= 12.272700786590576) {
                            { double _tmp[] = {0.8, 0.0, 0.2}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 14.914999961853027) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.196990966796875) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[6] <= 20.570000648498535) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2222222222222222, 0.037037037037037035, 0.7407407407407407}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[4] <= 13.389999866485596) {
                    if (input[16] <= 2.584999918937683) {
                        if (input[1] <= 33.72500038146973) {
                            { double _tmp[] = {0.9642857142857143, 0.03571428571428571, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6, 0.4, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= -0.9829629063606262) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4690265486725664, 0.5309734513274337, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 0.949999988079071) {
                        if (input[16] <= 4.585000038146973) {
                            { double _tmp[] = {0.3418803418803419, 0.0, 0.6581196581196581}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 1.034999966621399) {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.34782608695652173, 0.6521739130434783, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[1] <= 26.739999771118164) {
                if (input[9] <= 20.00527000427246) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[14] <= 0.6087097823619843) {
                        if (input[1] <= 26.43000030517578) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 58.44500160217285) {
                            { double _tmp[] = {0.6071428571428571, 0.21428571428571427, 0.17857142857142858}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[5] <= 36.72500038146973) {
                    if (input[17] <= 8.579999923706055) {
                        if (input[15] <= 0.9785950481891632) {
                            { double _tmp[] = {0.8467966573816156, 0.15041782729805014, 0.002785515320334262}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 24.885000228881836) {
                            { double _tmp[] = {0.125, 0.875, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 39.69999885559082) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[8] <= 93.80615615844727) {
                            { double _tmp[] = {0.4827586206896552, 0.5172413793103449, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.95, 0.0, 0.05}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[9] <= 20.314931869506836) {
            if (input[11] <= 22.966288566589355) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[11] <= 23.076163291931152) {
                    { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                }
            }
        } else {
            if (input[8] <= 94.99251556396484) {
                if (input[4] <= 13.40999984741211) {
                    if (input[17] <= -0.8549999892711639) {
                        if (input[2] <= 89.11000061035156) {
                            { double _tmp[] = {0.0, 0.3333333333333333, 0.6666666666666666}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 0.42499999701976776) {
                            { double _tmp[] = {0.0, 0.8974358974358975, 0.10256410256410256}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[16] <= 4.369999885559082) {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var27, _tmp, 3 * sizeof(double)); }
            }
        }
    }
    add_vectors(var14, var27, 3, var13);
    double var28[3];
    if (input[3] <= 503.7050018310547) {
        if (input[5] <= 36.28000068664551) {
            if (input[12] <= -0.9159756004810333) {
                if (input[11] <= 11.081316471099854) {
                    if (input[9] <= 20.00608730316162) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[16] <= 4.2149999141693115) {
                            { double _tmp[] = {0.23809523809523808, 0.7380952380952381, 0.023809523809523808}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.45454545454545453, 0.0, 0.5454545454545454}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[13] <= -0.1294095218181611) {
                        if (input[17] <= 5.224999904632568) {
                            { double _tmp[] = {0.8843537414965986, 0.11564625850340136, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6578947368421053, 0.34210526315789475, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.5049423575401306) {
                            { double _tmp[] = {0.972568578553616, 0.02743142144638404, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8484848484848485, 0.15151515151515152, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[7] <= 0.42499999701976776) {
                    if (input[9] <= 19.810917854309082) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[9] <= 24.413267135620117) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7142857142857143, 0.0, 0.2857142857142857}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[8] <= 94.98506927490234) {
                            { double _tmp[] = {0.0, 0.9041095890410958, 0.0958904109589041}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= -0.9993703663349152) {
                            { double _tmp[] = {0.8, 0.2, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9975704567541303, 0.0024295432458697765, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[0] <= 13.5) {
                if (input[12] <= -0.12940952181816096) {
                    if (input[14] <= 0.03442033752799034) {
                        if (input[3] <= 396.0900115966797) {
                            { double _tmp[] = {0.9807692307692307, 0.019230769230769232, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8666666666666667, 0.13333333333333333, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 15.97295331954956) {
                            { double _tmp[] = {0.125, 0.875, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6956521739130435, 0.30434782608695654, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.336143493652344) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[8] <= 94.99650573730469) {
                            { double _tmp[] = {0.0, 0.9375, 0.0625}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[3] <= 425.0850067138672) {
                    if (input[11] <= 17.81521701812744) {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.431924882629108, 0.568075117370892, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.2261904761904762, 0.023809523809523808}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 64.78999710083008) {
                            { double _tmp[] = {0.7229437229437229, 0.27705627705627706, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.42857142857142855, 0.5714285714285714, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[14] <= 0.7554863095283508) {
                        if (input[14] <= 0.1754908561706543) {
                            { double _tmp[] = {0.75, 0.25, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.14583333333333334, 0.8541666666666666, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 19.773584365844727) {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2222222222222222, 0.7777777777777778, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[5] <= 43.89000129699707) {
            if (input[5] <= 43.05000114440918) {
                if (input[12] <= -0.24999999999999994) {
                    if (input[17] <= 14.815000057220459) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[4] <= 13.46500015258789) {
                        if (input[6] <= 21.4350004196167) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 27.335000038146973) {
                            { double _tmp[] = {0.9781021897810219, 0.0072992700729927005, 0.014598540145985401}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[10] <= 14.432185173034668) {
                    if (input[3] <= 576.2250061035156) {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[1] <= 24.575000762939453) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[6] <= 23.809999465942383) {
                        if (input[1] <= 24.949999809265137) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 26.789999961853027) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.625, 0.25, 0.125}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[6] <= 25.36500072479248) {
                if (input[7] <= 1.2350000143051147) {
                    if (input[15] <= 0.3496344983577728) {
                        if (input[9] <= 20.12009906768799) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2698412698412698, 0.015873015873015872, 0.7142857142857143}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.000289916992188) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.18584070796460178, 0.008849557522123894, 0.8053097345132744}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 95.00650024414062) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                if (input[9] <= 20.02027130126953) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[9] <= 21.643238067626953) {
                        if (input[7] <= 1.0800000131130219) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var28, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var13, var28, 3, var12);
    double var29[3];
    if (input[4] <= 13.394999980926514) {
        if (input[17] <= 3.9850000143051147) {
            if (input[9] <= 20.000361442565918) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[11] <= 15.847100734710693) {
                    if (input[13] <= -0.00000000000000006123233601181349) {
                        if (input[9] <= 29.650802612304688) {
                            { double _tmp[] = {0.034482758620689655, 0.9655172413793104, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8421052631578948, 0.052631578947368425, 0.10526315789473685}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 0.9150000214576721) {
                            { double _tmp[] = {0.7754385964912281, 0.20350877192982458, 0.02105263157894737}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.38461538461538464, 0.6153846153846154, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                }
            }
        } else {
            if (input[0] <= 13.5) {
                if (input[17] <= 13.864999771118164) {
                    if (input[16] <= 3.8549998998641968) {
                        if (input[4] <= 7.894999980926514) {
                            { double _tmp[] = {0.8918918918918919, 0.10810810810810811, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.986827661909989, 0.013172338090010977, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 69.16999816894531) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5714285714285714, 0.42857142857142855, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[6] <= 26.479999542236328) {
                        if (input[14] <= 0.030106639489531517) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9550561797752809, 0.02247191011235955, 0.02247191011235955}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 21.806246757507324) {
                            { double _tmp[] = {0.36363636363636365, 0.6363636363636364, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8947368421052632, 0.10526315789473684, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 95.01407623291016) {
                    if (input[13] <= -0.379409521818161) {
                        if (input[10] <= 23.90915012359619) {
                            { double _tmp[] = {0.48507462686567165, 0.5, 0.014925373134328358}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6536585365853659, 0.3463414634146341, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.97842788696289) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.17142857142857143, 0.8285714285714286, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[9] <= 20.011646270751953) {
            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
        } else {
            if (input[21] <= 0.5) {
                if (input[11] <= 12.262054443359375) {
                    if (input[12] <= -0.379409521818161) {
                        if (input[16] <= 4.2099997997283936) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 21.64390468597412) {
                        if (input[0] <= 12.5) {
                            { double _tmp[] = {0.0, 0.06666666666666667, 0.9333333333333333}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.625, 0.375}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 22.989757537841797) {
                            { double _tmp[] = {0.0, 0.07317073170731707, 0.926829268292683}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.25, 0.75}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[10] <= 16.56876564025879) {
                    if (input[14] <= 0.7174376547336578) {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[14] <= 0.7526389360427856) {
                            { double _tmp[] = {0.7777777777777778, 0.2222222222222222, 0.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.94, 0.0, 0.06}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 23.771477699279785) {
                        if (input[10] <= 19.318920135498047) {
                            { double _tmp[] = {0.09090909090909091, 0.36363636363636365, 0.5454545454545454}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 15.305103302001953) {
                            { double _tmp[] = {0.8695652173913043, 0.08695652173913043, 0.043478260869565216}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.16666666666666666, 0.8333333333333334}; memcpy(var29, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var12, var29, 3, var11);
    double var30[3];
    if (input[18] <= 0.5) {
        if (input[16] <= 3.2450000047683716) {
            if (input[0] <= 18.5) {
                if (input[20] <= 0.5) {
                    if (input[10] <= 15.843462944030762) {
                        if (input[5] <= 16.875) {
                            { double _tmp[] = {0.25, 0.75, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8604651162790697, 0.13953488372093023, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[12] <= 0.9159756004810333) {
                            { double _tmp[] = {0.37037037037037035, 0.6296296296296297, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2222222222222222, 0.2222222222222222, 0.5555555555555556}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[1] <= 24.300000190734863) {
                        if (input[19] <= 0.5) {
                            { double _tmp[] = {0.9932885906040269, 0.006711409395973154, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 24.3149995803833) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9084507042253521, 0.09154929577464789, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[16] <= 3.1149998903274536) {
                    if (input[9] <= 20.347567558288574) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[14] <= 0.2911748681217432) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 63.130001068115234) {
                        if (input[9] <= 34.00278091430664) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[2] <= 78.31500244140625) {
                if (input[7] <= 0.679999977350235) {
                    if (input[5] <= 26.2450008392334) {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 8.790870189666748) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[14] <= 0.26536503434181213) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9295774647887324, 0.07042253521126761, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[7] <= 4.480000019073486) {
                    if (input[10] <= 15.638344764709473) {
                        if (input[2] <= 79.90500259399414) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[11] <= 13.112056732177734) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[4] <= 13.555000305175781) {
            if (input[19] <= 0.5) {
                if (input[1] <= 26.744999885559082) {
                    if (input[5] <= 41.795000076293945) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.9459459459459459, 0.0, 0.05405405405405406}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9854227405247813, 0.014577259475218658, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 13.407951831817627) {
                            { double _tmp[] = {0.0, 0.5, 0.5}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[12] <= -0.379409521818161) {
                        if (input[13] <= -0.379409521818161) {
                            { double _tmp[] = {0.5486443381180223, 0.4481658692185007, 0.003189792663476873}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8042553191489362, 0.19574468085106383, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[3] <= 437.5050048828125) {
                            { double _tmp[] = {0.987603305785124, 0.012396694214876033, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8468468468468469, 0.14414414414414414, 0.009009009009009009}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[1] <= 22.299999237060547) {
                    if (input[2] <= 70.65499877929688) {
                        if (input[10] <= 15.377723217010498) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.20499999821186066) {
                            { double _tmp[] = {0.4, 0.6, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.989010989010989, 0.01098901098901099, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[14] <= -0.8587321639060974) {
                        if (input[2] <= 84.80000305175781) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[1] <= 26.704999923706055) {
                if (input[3] <= 598.8049926757812) {
                    if (input[17] <= 14.894999980926514) {
                        if (input[7] <= 1.5450000166893005) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 23.8149995803833) {
                            { double _tmp[] = {0.9441340782122905, 0.0, 0.055865921787709494}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.0, 0.5}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[3] <= 604.8099975585938) {
                        if (input[8] <= 82.6280288696289) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 28.495556831359863) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8181818181818182, 0.012987012987012988, 0.16883116883116883}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[15] <= -0.5981587469577789) {
                    if (input[0] <= 12.5) {
                        if (input[16] <= 3.4950000047683716) {
                            { double _tmp[] = {0.9574468085106383, 0.0, 0.0425531914893617}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7333333333333333, 0.0, 0.26666666666666666}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 94.97494125366211) {
                            { double _tmp[] = {0.21739130434782608, 0.043478260869565216, 0.7391304347826086}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[12] <= 0.12940952181816107) {
                        if (input[7] <= 0.9749999940395355) {
                            { double _tmp[] = {0.2971887550200803, 0.0, 0.7028112449799196}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.25, 0.75, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var30, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var11, var30, 3, var10);
    double var31[3];
    if (input[18] <= 0.5) {
        if (input[1] <= 24.714999198913574) {
            if (input[16] <= 3.1850000619888306) {
                if (input[15] <= 0.9999259114265442) {
                    if (input[9] <= 22.466665267944336) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[7] <= 2.524999976158142) {
                            { double _tmp[] = {0.052631578947368425, 0.8421052631578948, 0.10526315789473685}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.898876404494382, 0.10112359550561797, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 17.979999542236328) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                if (input[8] <= 94.98286056518555) {
                    if (input[20] <= 0.5) {
                        if (input[6] <= 15.389999866485596) {
                            { double _tmp[] = {0.0, 0.8888888888888888, 0.1111111111111111}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                }
            }
        } else {
            if (input[2] <= 44.385000228881836) {
                { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[11] <= 11.08434009552002) {
                    if (input[9] <= 19.862725257873535) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[8] <= 95.06392288208008) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[4] <= 2.75) {
                        if (input[0] <= 12.5) {
                            { double _tmp[] = {0.8085106382978723, 0.19148936170212766, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9970014992503748, 0.0029985007496251873, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.97025489807129) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5294117647058824, 0.4411764705882353, 0.029411764705882353}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[12] <= 0.12940952181816107) {
            if (input[9] <= 19.999879837036133) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[9] <= 27.048574447631836) {
                    if (input[12] <= -0.379409521818161) {
                        if (input[6] <= 26.405000686645508) {
                            { double _tmp[] = {0.06091370558375635, 0.6446700507614214, 0.29441624365482233}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.021505376344086023, 0.946236559139785, 0.03225806451612903}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= -0.9910896420478821) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.009302325581395349, 0.11627906976744186, 0.8744186046511628}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[15] <= 0.8424220979213715) {
                        if (input[2] <= 61.81999969482422) {
                            { double _tmp[] = {0.972972972972973, 0.0, 0.02702702702702703}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 12.739590167999268) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[0] <= 10.5) {
                if (input[16] <= 3.6149998903274536) {
                    if (input[4] <= 11.925000190734863) {
                        if (input[10] <= 24.67184829711914) {
                            { double _tmp[] = {0.9892617449664429, 0.010738255033557046, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9166666666666666, 0.08333333333333333, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[2] <= 72.31000137329102) {
                        if (input[15] <= 0.9999259114265442) {
                            { double _tmp[] = {0.9878048780487805, 0.012195121951219513, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                if (input[9] <= 20.159289360046387) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[7] <= 0.9599999785423279) {
                        if (input[8] <= 95.11262512207031) {
                            { double _tmp[] = {0.0, 0.08333333333333333, 0.9166666666666666}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 23.414999961853027) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var31, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var10, var31, 3, var9);
    double var32[3];
    if (input[9] <= 19.999879837036133) {
        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
    } else {
        if (input[5] <= 43.9950008392334) {
            if (input[5] <= 33.28000068664551) {
                if (input[15] <= 0.7142498791217804) {
                    if (input[8] <= 94.99926376342773) {
                        if (input[14] <= 0.8542905151844025) {
                            { double _tmp[] = {0.0, 0.8695652173913043, 0.13043478260869565}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[5] <= 32.22499942779541) {
                        if (input[8] <= 47.874481201171875) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.06666666666666667, 0.8666666666666667, 0.06666666666666667}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.9907664954662323) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[6] <= 23.71500015258789) {
                    if (input[11] <= 10.2937650680542) {
                        if (input[3] <= 484.8999938964844) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.1111111111111111, 0.1111111111111111, 0.7777777777777778}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 23.449999809265137) {
                            { double _tmp[] = {0.92, 0.04, 0.04}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4, 0.0, 0.6}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[6] <= 26.065000534057617) {
                        if (input[7] <= 1.550000011920929) {
                            { double _tmp[] = {0.21, 0.77, 0.02}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9444444444444444, 0.05555555555555555, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2222222222222222, 0.7777777777777778, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[3] <= 502.0449981689453) {
                if (input[21] <= 0.5) {
                    { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[8] <= 94.5591812133789) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                if (input[15] <= 0.6963504254817963) {
                    if (input[9] <= 25.9329195022583) {
                        if (input[15] <= -0.46734189987182617) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.008130081300813009, 0.24390243902439024, 0.7479674796747967}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 94.99332809448242) {
                            { double _tmp[] = {0.0, 0.5, 0.5}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var32, _tmp, 3 * sizeof(double)); }
                }
            }
        }
    }
    add_vectors(var9, var32, 3, var8);
    double var33[3];
    if (input[1] <= 26.704999923706055) {
        if (input[9] <= 20.004332542419434) {
            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
        } else {
            if (input[4] <= 13.420000076293945) {
                if (input[8] <= 94.98890686035156) {
                    if (input[11] <= 8.626338481903076) {
                        if (input[13] <= 0.0) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 34.242788314819336) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.8688524590163934, 0.13114754098360656}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                }
            } else {
                if (input[9] <= 27.666980743408203) {
                    if (input[2] <= 62.7400016784668) {
                        if (input[7] <= 0.7699999809265137) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.3257784992456436) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[15] <= 0.6583772003650665) {
                        if (input[15] <= 0.6453242003917694) {
                            { double _tmp[] = {0.9655172413793104, 0.0, 0.034482758620689655}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.0, 0.6666666666666666}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[18] <= 0.5) {
            if (input[2] <= 44.760000228881836) {
                { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[1] <= 32.18499946594238) {
                    if (input[0] <= 18.5) {
                        if (input[16] <= 3.759999990463257) {
                            { double _tmp[] = {0.9397590361445783, 0.060240963855421686, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.0, 0.2}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[10] <= 23.976080894470215) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[9] <= 19.97025489807129) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[4] <= 13.394999980926514) {
                if (input[16] <= 2.284999966621399) {
                    if (input[10] <= 26.60983180999756) {
                        if (input[1] <= 31.989999771118164) {
                            { double _tmp[] = {0.9900990099009901, 0.009900990099009901, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8275862068965517, 0.1724137931034483, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.154626846313477) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.001455307006836) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.8421052631578948, 0.09210526315789475, 0.06578947368421054}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.023323615160349854, 0.9766763848396501, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[0] <= 11.5) {
                    if (input[9] <= 45.93603515625) {
                        if (input[1] <= 26.734999656677246) {
                            { double _tmp[] = {0.5, 0.0, 0.5}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 20.007081031799316) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[9] <= 24.63049030303955) {
                            { double _tmp[] = {0.018604651162790697, 0.1813953488372093, 0.8}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8301886792452831, 0.03773584905660377, 0.1320754716981132}; memcpy(var33, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var8, var33, 3, var7);
    double var34[3];
    if (input[17] <= 14.744999885559082) {
        if (input[1] <= 27.84500026702881) {
            if (input[16] <= 3.5649999380111694) {
                if (input[2] <= 51.27499961853027) {
                    if (input[16] <= 2.9550000429153442) {
                        if (input[15] <= 0.9937097728252411) {
                            { double _tmp[] = {0.7763157894736842, 0.2236842105263158, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2222222222222222, 0.7777777777777778, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 16.452173233032227) {
                            { double _tmp[] = {0.9772727272727273, 0.022727272727272728, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[17] <= 0.7450000047683716) {
                        if (input[12] <= -0.9829629063606262) {
                            { double _tmp[] = {0.7636363636363637, 0.23636363636363636, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9734982332155477, 0.023409893992932862, 0.0030918727915194345}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 5.735000133514404) {
                            { double _tmp[] = {0.9946902654867257, 0.005309734513274336, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 94.98669815063477) {
                    if (input[13] <= -0.379409521818161) {
                        if (input[5] <= 38.614999771118164) {
                            { double _tmp[] = {0.9565217391304348, 0.043478260869565216, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2857142857142857, 0.7142857142857143, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.879999965429306) {
                            { double _tmp[] = {0.0, 0.6, 0.4}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                }
            }
        } else {
            if (input[4] <= 7.075000047683716) {
                if (input[14] <= 0.8475330770015717) {
                    if (input[17] <= 3.8600000143051147) {
                        if (input[14] <= -0.9275073111057281) {
                            { double _tmp[] = {0.8, 0.2, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9948051948051948, 0.005194805194805195, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 18.322505950927734) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 44.6778564453125) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[9] <= 19.936394691467285) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[11] <= 15.436214923858643) {
                    if (input[4] <= 8.260000228881836) {
                        if (input[11] <= 10.231282234191895) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.2, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.4121212121212121, 0.5878787878787879, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6509433962264152, 0.339622641509434, 0.009433962264150945}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[0] <= 13.5) {
                        if (input[3] <= 426.14500427246094) {
                            { double _tmp[] = {0.9900332225913622, 0.009966777408637873, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8765432098765432, 0.1111111111111111, 0.012345679012345678}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.99988842010498) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.02, 0.98, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[6] <= 22.454999923706055) {
            if (input[12] <= 0.379409521818161) {
                if (input[2] <= 57.55500030517578) {
                    if (input[9] <= 20.147778511047363) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[4] <= 15.204999923706055) {
                            { double _tmp[] = {0.3333333333333333, 0.0, 0.6666666666666666}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8333333333333334, 0.0, 0.16666666666666666}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 71.67886734008789) {
                        if (input[2] <= 59.829999923706055) {
                            { double _tmp[] = {0.1111111111111111, 0.0, 0.8888888888888888}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[3] <= 628.6749877929688) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[17] <= 14.815000057220459) {
                    if (input[21] <= 0.5) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[12] <= 0.6035533845424652) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[8] <= 55.83858108520508) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[12] <= 0.12940952181816107) {
                if (input[9] <= 19.999879837036133) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[3] <= 500.22999572753906) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[14] <= 0.732487291097641) {
                            { double _tmp[] = {0.0660377358490566, 0.009433962264150943, 0.9245283018867925}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.24025974025974026, 0.14935064935064934, 0.6103896103896104}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[3] <= 653.4950256347656) {
                    if (input[14] <= 0.9993241131305695) {
                        if (input[8] <= 94.57440567016602) {
                            { double _tmp[] = {0.9897959183673469, 0.0, 0.01020408163265306}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.0, 0.3333333333333333}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[6] <= 23.475000381469727) {
                        if (input[9] <= 28.881685256958008) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var34, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var7, var34, 3, var6);
    double var35[3];
    if (input[17] <= 15.515000343322754) {
        if (input[1] <= 27.260000228881836) {
            if (input[2] <= 45.30500030517578) {
                if (input[14] <= 0.06879223324358463) {
                    { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[5] <= 37.8700008392334) {
                        if (input[9] <= 26.557766914367676) {
                            { double _tmp[] = {0.9047619047619048, 0.09523809523809523, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 42.09000015258789) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 20.029013633728027) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[14] <= 0.523396223783493) {
                        if (input[12] <= 0.9159756004810333) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.6666666666666666, 0.3333333333333333}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 1.9200000166893005) {
                            { double _tmp[] = {0.6315789473684211, 0.3026315789473685, 0.06578947368421054}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.921146953405018, 0.07885304659498207, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[0] <= 17.5) {
                if (input[2] <= 61.35000038146973) {
                    if (input[3] <= 177.23999786376953) {
                        if (input[5] <= 31.640000343322754) {
                            { double _tmp[] = {0.3, 0.7, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8518518518518519, 0.14814814814814814, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[12] <= -0.379409521818161) {
                            { double _tmp[] = {0.5074309978768577, 0.4819532908704883, 0.010615711252653927}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8695652173913043, 0.13043478260869565, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 26.81471061706543) {
                        if (input[7] <= 0.6600000187754631) {
                            { double _tmp[] = {0.9405940594059405, 0.055445544554455446, 0.0039603960396039604}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.625, 0.375, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.97679901123047) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[14] <= 0.5379254817962646) {
                    if (input[15] <= -0.9993703663349152) {
                        if (input[6] <= 28.8799991607666) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6, 0.4, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 4.810250520706177) {
                            { double _tmp[] = {0.9875, 0.0125, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[14] <= 0.5560123026371002) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[10] <= 18.697879791259766) {
                            { double _tmp[] = {0.8, 0.2, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[16] <= 3.3049999475479126) {
            if (input[12] <= 0.12940952181816107) {
                if (input[7] <= 0.9900000095367432) {
                    if (input[2] <= 60.625) {
                        if (input[8] <= 95.3100357055664) {
                            { double _tmp[] = {0.3194444444444444, 0.027777777777777776, 0.6527777777777778}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 21.706503868103027) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.0, 0.5}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[6] <= 25.53499984741211) {
                        if (input[3] <= 575.5449829101562) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                if (input[5] <= 44.30000114440918) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[17] <= 17.604999542236328) {
                        if (input[17] <= 17.354999542236328) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[5] <= 43.52499961853027) {
                if (input[9] <= 20.056493759155273) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[2] <= 48.920000076293945) {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9333333333333333, 0.0, 0.06666666666666667}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[12] <= 0.12940952181816107) {
                    if (input[9] <= 20.014989852905273) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[8] <= 94.98316192626953) {
                            { double _tmp[] = {0.0, 0.11834319526627218, 0.8816568047337278}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 54.454999923706055) {
                        if (input[11] <= 11.312472343444824) {
                            { double _tmp[] = {0.7058823529411765, 0.058823529411764705, 0.23529411764705882}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= 0.5863924026489258) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8666666666666667, 0.044444444444444446, 0.08888888888888889}; memcpy(var35, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var6, var35, 3, var5);
    double var36[3];
    if (input[1] <= 26.704999923706055) {
        if (input[3] <= 595.1099853515625) {
            if (input[8] <= 94.68511199951172) {
                if (input[16] <= 3.3649998903274536) {
                    if (input[8] <= 50.29384803771973) {
                        if (input[8] <= 50.25643539428711) {
                            { double _tmp[] = {0.9665551839464883, 0.028428093645484948, 0.005016722408026756}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9962264150943396, 0.0037735849056603774, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[5] <= 17.03499984741211) {
                            { double _tmp[] = {0.0, 0.75, 0.25}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.9993334114551544) {
                            { double _tmp[] = {0.9285714285714286, 0.044642857142857144, 0.026785714285714284}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 94.99926376342773) {
                    if (input[5] <= 25.0600004196167) {
                        if (input[12] <= 0.9159756004810333) {
                            { double _tmp[] = {0.029411764705882353, 0.9705882352941176, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.127283096313477) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.25, 0.75}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                }
            }
        } else {
            if (input[8] <= 46.85335731506348) {
                if (input[12] <= 0.12940952181816107) {
                    { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[6] <= 21.47000026702881) {
                        if (input[6] <= 21.02999973297119) {
                            { double _tmp[] = {0.5, 0.0, 0.5}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                    }
                }
            } else {
                if (input[17] <= 17.96500015258789) {
                    if (input[3] <= 611.39501953125) {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[2] <= 50.97500038146973) {
                        if (input[6] <= 21.135000228881836) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.36363636363636365, 0.0, 0.6363636363636364}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.384999990463257) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.025, 0.175}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[0] <= 17.5) {
            if (input[14] <= 0.04732095077633858) {
                if (input[0] <= 13.5) {
                    if (input[5] <= 47.57500076293945) {
                        if (input[12] <= 0.9159756004810333) {
                            { double _tmp[] = {0.9775, 0.0225, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 31.15499973297119) {
                            { double _tmp[] = {0.6666666666666666, 0.0, 0.3333333333333333}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[16] <= 3.5049999952316284) {
                        if (input[16] <= 2.3249999284744263) {
                            { double _tmp[] = {0.9130434782608695, 0.08695652173913043, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6958333333333333, 0.3, 0.004166666666666667}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= -0.9915303885936737) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.14285714285714285, 0.8571428571428571, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 19.996185302734375) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[3] <= 502.1499938964844) {
                        if (input[8] <= 95.02390670776367) {
                            { double _tmp[] = {0.03007518796992481, 0.9586466165413534, 0.011278195488721804}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= 0.5270728468894958) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.19111111111111112, 0.19555555555555557, 0.6133333333333333}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[4] <= 2.75) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[7] <= 0.26000000536441803) {
                    if (input[16] <= 4.105000019073486) {
                        if (input[17] <= -0.9600000083446503) {
                            { double _tmp[] = {0.8571428571428571, 0.14285714285714285, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9770992366412213, 0.022900763358778626, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[1] <= 27.074999809265137) {
                        if (input[17] <= 0.6400000005960464) {
                            { double _tmp[] = {0.25, 0.75, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.489865317940712) {
                            { double _tmp[] = {0.9423076923076923, 0.057692307692307696, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.631578947368421, 0.3684210526315789, 0.0}; memcpy(var36, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var5, var36, 3, var4);
    double var37[3];
    if (input[9] <= 19.999879837036133) {
        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
    } else {
        if (input[9] <= 25.965112686157227) {
            if (input[3] <= 501.94500732421875) {
                if (input[4] <= 2.75) {
                    if (input[9] <= 24.845901489257812) {
                        if (input[8] <= 63.46471691131592) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[2] <= 39.69999885559082) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[7] <= 1.7300000190734863) {
                            { double _tmp[] = {0.007462686567164179, 0.9925373134328358, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[2] <= 65.18500137329102) {
                    if (input[2] <= 51.25) {
                        if (input[16] <= 4.2099997997283936) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.25, 0.75}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.9749999940395355) {
                            { double _tmp[] = {0.007462686567164179, 0.0, 0.9925373134328358}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.08333333333333333, 0.9166666666666666, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                }
            }
        } else {
            if (input[0] <= 7.5) {
                if (input[14] <= 0.523396223783493) {
                    if (input[13] <= 0.7865660786628723) {
                        if (input[11] <= 9.051862239837646) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.7777777777777778, 0.2222222222222222}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[15] <= 0.03011918906122446) {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.0, 0.8571428571428571, 0.14285714285714285}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9230769230769231, 0.07692307692307693, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 2.5549999475479126) {
                            { double _tmp[] = {0.3157894736842105, 0.631578947368421, 0.05263157894736842}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9431818181818182, 0.056818181818181816, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[10] <= 13.498851299285889) {
                    if (input[17] <= 5.130000114440918) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[2] <= 49.69499969482422) {
                            { double _tmp[] = {0.25, 0.75, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.0, 0.2}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[16] <= 4.115000009536743) {
                        if (input[14] <= 0.3594783917069435) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9398907103825137, 0.04371584699453552, 0.01639344262295082}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.6583772003650665) {
                            { double _tmp[] = {0.8113207547169812, 0.03773584905660377, 0.1509433962264151}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var37, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var4, var37, 3, var3);
    double var38[3];
    if (input[2] <= 57.97500038146973) {
        if (input[5] <= 44.34499931335449) {
            if (input[13] <= -0.379409521818161) {
                if (input[6] <= 23.229999542236328) {
                    if (input[14] <= 0.008606677874922752) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[2] <= 57.670000076293945) {
                            { double _tmp[] = {0.9411764705882354, 0.013071895424836603, 0.04575163398692811}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.0, 0.3333333333333333}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 20.975971221923828) {
                        if (input[8] <= 90.31864547729492) {
                            { double _tmp[] = {0.3487394957983193, 0.5966386554621849, 0.0546218487394958}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8571428571428572, 0.10000000000000002, 0.042857142857142864}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= -0.8170740604400635) {
                            { double _tmp[] = {0.782608695652174, 0.21739130434782608, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[2] <= 45.97500038146973) {
                    if (input[8] <= 51.355642318725586) {
                        if (input[2] <= 39.80500030517578) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.07142857142857142, 0.9285714285714286, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 4.25) {
                            { double _tmp[] = {0.5, 0.5, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 17.058926582336426) {
                        if (input[5] <= 33.189998626708984) {
                            { double _tmp[] = {0.9530516431924883, 0.03286384976525822, 0.014084507042253521}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8181818181818182, 0.18181818181818182, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 5.620000123977661) {
                            { double _tmp[] = {0.883495145631068, 0.11650485436893204, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.25, 0.75, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[3] <= 501.7099914550781) {
                if (input[9] <= 19.553098678588867) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[21] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[8] <= 90.57295608520508) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[7] <= 1.0199999809265137) {
                    if (input[20] <= 0.5) {
                        if (input[9] <= 28.427888870239258) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9743589743589743, 0.0, 0.02564102564102564}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 21.700000762939453) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.332, 0.0, 0.668}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 12.692667484283447) {
                        if (input[3] <= 573.6700134277344) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= -0.9829629063606262) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.15384615384615385, 0.8461538461538461, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[9] <= 19.999879837036133) {
            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
        } else {
            if (input[10] <= 20.6663179397583) {
                if (input[21] <= 0.5) {
                    if (input[4] <= 13.330000400543213) {
                        if (input[17] <= -0.7749999761581421) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.92, 0.08}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[4] <= 15.085000038146973) {
                            { double _tmp[] = {0.0, 0.08333333333333333, 0.9166666666666666}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.6666666666666666, 0.3333333333333333}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 23.620882987976074) {
                        if (input[5] <= 41.65500068664551) {
                            { double _tmp[] = {0.631578947368421, 0.3684210526315789, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2222222222222222, 0.0, 0.7777777777777778}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 94.98286056518555) {
                            { double _tmp[] = {0.0, 0.9565217391304348, 0.043478260869565216}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[14] <= 0.3530343919992447) {
                    if (input[4] <= 13.349999904632568) {
                        if (input[1] <= 23.039999961853027) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 45.668195724487305) {
                        if (input[17] <= 15.315000057220459) {
                            { double _tmp[] = {0.0, 0.896551724137931, 0.10344827586206896}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.05555555555555555, 0.9444444444444444}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var38, _tmp, 3 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var3, var38, 3, var2);
    double var39[3];
    if (input[2] <= 58.864999771118164) {
        if (input[5] <= 44.28499984741211) {
            if (input[9] <= 20.00141429901123) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[8] <= 95.00228118896484) {
                    if (input[4] <= 13.40999984741211) {
                        if (input[9] <= 25.965112686157227) {
                            { double _tmp[] = {0.00423728813559322, 0.9957627118644068, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2647058823529412, 0.5294117647058824, 0.20588235294117646}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 16.541479110717773) {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                }
            }
        } else {
            if (input[4] <= 13.440000057220459) {
                if (input[0] <= 13.5) {
                    if (input[5] <= 45.93000030517578) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[16] <= 3.3600000143051147) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 44.59000015258789) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[2] <= 54.95500183105469) {
                            { double _tmp[] = {0.8333333333333334, 0.16666666666666666, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2, 0.8, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 94.99259185791016) {
                    if (input[7] <= 1.0199999809265137) {
                        if (input[6] <= 21.700000762939453) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.337037037037037, 0.0, 0.662962962962963}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.4514695107936859) {
                            { double _tmp[] = {0.13793103448275862, 0.8620689655172413, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[1] <= 31.260000228881836) {
            if (input[9] <= 20.00685691833496) {
                { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
            } else {
                if (input[7] <= 1.3849999904632568) {
                    if (input[3] <= 503.86000061035156) {
                        if (input[6] <= 20.53499984741211) {
                            { double _tmp[] = {0.45161290322580644, 0.45161290322580644, 0.0967741935483871}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.5, 0.5, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 2.7799999713897705) {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9367088607594937, 0.06329113924050633, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 89.0099983215332) {
                            { double _tmp[] = {0.8837209302325582, 0.11627906976744186, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[10] <= 22.960851669311523) {
                if (input[3] <= 137.5250015258789) {
                    { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                } else {
                    if (input[4] <= 12.59499979019165) {
                        { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[5] <= 46.11000061035156) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[3] <= 111.63000106811523) {
                    if (input[11] <= 18.459633827209473) {
                        if (input[9] <= 19.78952121734619) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 3.8600000143051147) {
                            { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.04717254638672) {
                        { double _tmp[] = {1.0, 0.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                    } else {
                        if (input[3] <= 491.20001220703125) {
                            { double _tmp[] = {0.0, 1.0, 0.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 0.0, 1.0}; memcpy(var39, _tmp, 3 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var2, var39, 3, var1);
    mul_vector_number(var1, 0.05, 3, var0);
    memcpy(output, var0, 3 * sizeof(double));
}
