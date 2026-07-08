#pragma once

#include "control/generated/model_utils.h"

#include <string.h>


inline void predict_vcrc_state(const double * input, double * output) {
    double var0[2];
    double var1[2];
    double var2[2];
    double var3[2];
    double var4[2];
    double var5[2];
    double var6[2];
    double var7[2];
    double var8[2];
    double var9[2];
    double var10[2];
    double var11[2];
    double var12[2];
    double var13[2];
    double var14[2];
    double var15[2];
    double var16[2];
    double var17[2];
    double var18[2];
    double var19[2];
    double var20[2];
    if (input[5] <= 37.08500099182129) {
        if (input[16] <= 3.2450000047683716) {
            if (input[9] <= 19.998287200927734) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[8] <= 94.98080444335938) {
                    if (input[15] <= 0.9919434785842896) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[4] <= 6.84499979019165) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[14] <= 0.1542859524488449) {
                if (input[16] <= 3.4450000524520874) {
                    if (input[0] <= 7.0) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[2] <= 49.11000061035156) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[8] <= 94.99926376342773) {
                    if (input[4] <= 8.164999961853027) {
                        if (input[6] <= 24.69499969482422) {
                            { double _tmp[] = {0.024390243902439025, 0.975609756097561}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8333333333333334, 0.16666666666666666}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.6850000619888306) {
                            { double _tmp[] = {0.96, 0.04}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[2] <= 59.125) {
            if (input[1] <= 25.72499942779541) {
                if (input[16] <= 3.3700000047683716) {
                    if (input[11] <= 11.159483909606934) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[15] <= 0.5949931144714355) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 57.84000015258789) {
                        if (input[16] <= 3.700000047683716) {
                            { double _tmp[] = {0.46153846153846156, 0.5384615384615384}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.875, 0.125}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[15] <= 0.7086004316806793) {
                    if (input[9] <= 19.992557525634766) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[8] <= 95.0388298034668) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 40.07499885559082) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[5] <= 38.28000068664551) {
                            { double _tmp[] = {0.047619047619047616, 0.9523809523809523}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.30927835051546393, 0.6907216494845361}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[4] <= 15.375) {
                if (input[9] <= 20.011564254760742) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[6] <= 22.889999389648438) {
                        if (input[14] <= 0.809615969657898) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 25.99071979522705) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.2}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[5] <= 47.60499954223633) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[1] <= 29.22000026702881) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    double var21[2];
    if (input[2] <= 61.385000228881836) {
        if (input[8] <= 94.99821853637695) {
            if (input[4] <= 8.074999809265137) {
                if (input[9] <= 19.980029106140137) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[10] <= 12.52194356918335) {
                        if (input[6] <= 23.949999809265137) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[9] <= 20.00054359436035) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[6] <= 26.625) {
                        if (input[11] <= 8.866450309753418) {
                            { double _tmp[] = {0.9, 0.1}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.02891566265060241, 0.9710843373493976}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
        }
    } else {
        if (input[16] <= 3.4250000715255737) {
            if (input[10] <= 26.654340744018555) {
                if (input[1] <= 32.57500076293945) {
                    if (input[15] <= 0.9999259114265442) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.8482758620689655, 0.15172413793103448}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9926863572433192, 0.0073136427566807315}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.008514404296875) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[1] <= 33.71500015258789) {
                    if (input[9] <= 20.20714569091797) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[5] <= 38.89000129699707) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[3] <= 202.59500122070312) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.38461538461538464, 0.6153846153846154}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[10] <= 12.102231979370117) {
                { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[0] <= 1.5) {
                    if (input[2] <= 76.20499801635742) {
                        if (input[1] <= 18.824999809265137) {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 20.15178680419922) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[10] <= 20.788695335388184) {
                            { double _tmp[] = {0.8347107438016529, 0.1652892561983471}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.05555555555555555, 0.9444444444444444}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var20, var21, 2, var19);
    double var22[2];
    if (input[5] <= 37.44000053405762) {
        if (input[2] <= 55.79999923706055) {
            if (input[1] <= 27.260000228881836) {
                if (input[9] <= 19.990093231201172) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[1] <= 25.6200008392334) {
                            { double _tmp[] = {0.375, 0.625}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9545454545454546, 0.045454545454545456}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 22.03972816467285) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 19.954151153564453) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[8] <= 94.54814910888672) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[20] <= 0.5) {
                if (input[8] <= 95.00268173217773) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[6] <= 29.204999923706055) {
                    if (input[9] <= 19.983976364135742) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[1] <= 23.210000038146973) {
                            { double _tmp[] = {0.9523809523809523, 0.047619047619047616}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.25806451612903225, 0.7419354838709677}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 34.98112869262695) {
                        if (input[15] <= -0.44273316860198975) {
                            { double _tmp[] = {0.8557692307692307, 0.14423076923076922}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[0] <= 12.5) {
            if (input[2] <= 57.84000015258789) {
                if (input[5] <= 45.98000144958496) {
                    if (input[16] <= 3.0199999809265137) {
                        if (input[2] <= 44.630001068115234) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9811320754716981, 0.018867924528301886}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.1162748336792) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.42592592592592593, 0.5740740740740741}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[16] <= 3.165000081062317) {
                        if (input[17] <= 19.039999961853027) {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.8, 0.2}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.10810810810810811, 0.8918918918918919}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[17] <= 15.065000057220459) {
                    if (input[11] <= 21.42806911468506) {
                        if (input[5] <= 37.66499900817871) {
                            { double _tmp[] = {0.9411764705882353, 0.058823529411764705}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 26.11613655090332) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[17] <= 15.089999675750732) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 20.02292823791504) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.358974358974359, 0.6410256410256411}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[8] <= 94.99821853637695) {
                if (input[14] <= 0.20088869333267212) {
                    if (input[11] <= 19.484036445617676) {
                        if (input[16] <= 3.8299999237060547) {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.25, 0.75}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= -0.9159756004810333) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7071428571428572, 0.29285714285714287}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 1.3300000429153442) {
                        if (input[9] <= 19.992557525634766) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.009259259259259259, 0.9907407407407407}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 26.06999969482422) {
                            { double _tmp[] = {0.030303030303030304, 0.9696969696969697}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.375, 0.625}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var19, var22, 2, var18);
    double var23[2];
    if (input[2] <= 58.33500099182129) {
        if (input[0] <= 16.5) {
            if (input[0] <= 11.5) {
                if (input[9] <= 19.939708709716797) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[21] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[16] <= 4.794999837875366) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 95.0428695678711) {
                    if (input[9] <= 20.00141429901123) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 24.891796112060547) {
                            { double _tmp[] = {0.032036613272311214, 0.9679633867276888}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.45454545454545453, 0.5454545454545454}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[13] <= 0.12940952181816093) {
                if (input[14] <= 0.9828901588916779) {
                    if (input[9] <= 19.990134239196777) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[15] <= 0.5269996225833893) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5454545454545454, 0.45454545454545453}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[7] <= 2.575000047683716) {
                    if (input[8] <= 29.65464210510254) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.7692307692307693, 0.23076923076923078}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[14] <= 0.9189716875553131) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[5] <= 40.26499938964844) {
            if (input[9] <= 19.987102508544922) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[21] <= 0.5) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[17] <= 0.9099999964237213) {
                        if (input[10] <= 12.101481914520264) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9642857142857143, 0.03571428571428571}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.20999999344348907) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.86, 0.14}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[17] <= 8.214999675750732) {
                if (input[12] <= -0.7865660786628723) {
                    if (input[1] <= 32.72500038146973) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 20.406408309936523) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[16] <= 2.8249999284744263) {
                        if (input[14] <= -0.7902133166790009) {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.2}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 7.414999961853027) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[5] <= 43.989999771118164) {
                    if (input[4] <= 10.795000076293945) {
                        if (input[3] <= 335.3800048828125) {
                            { double _tmp[] = {0.8382352941176471, 0.16176470588235295}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 61.56500053405762) {
                            { double _tmp[] = {0.8181818181818182, 0.18181818181818182}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9692982456140351, 0.03070175438596491}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 55.99243354797363) {
                        if (input[11] <= 22.893451690673828) {
                            { double _tmp[] = {0.8085106382978723, 0.19148936170212766}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[12] <= -0.12940952181816096) {
                            { double _tmp[] = {0.13333333333333333, 0.8666666666666667}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.2}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var18, var23, 2, var17);
    double var24[2];
    if (input[5] <= 42.875) {
        if (input[13] <= -0.00000000000000006123233601181349) {
            if (input[16] <= 2.2450000047683716) {
                if (input[6] <= 25.734999656677246) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[11] <= 13.894991874694824) {
                        if (input[15] <= -0.5059591382741928) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.85, 0.15}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 32.20000076293945) {
                            { double _tmp[] = {0.9882352941176471, 0.011764705882352941}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8787878787878788, 0.12121212121212122}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[0] <= 13.5) {
                    if (input[6] <= 16.605000495910645) {
                        if (input[8] <= 88.36333847045898) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.42857142857142855, 0.5714285714285714}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= 0.999657392501831) {
                            { double _tmp[] = {0.9941520467836257, 0.005847953216374269}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 34.97999954223633) {
                        if (input[9] <= 19.9557523727417) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5058823529411764, 0.49411764705882355}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.7050000429153442) {
                            { double _tmp[] = {0.6263736263736264, 0.37362637362637363}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8947368421052632, 0.10526315789473684}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[8] <= 94.72148895263672) {
                if (input[8] <= 32.31964683532715) {
                    if (input[0] <= 12.5) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9977777777777778, 0.0022222222222222222}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.09371852874756) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[16] <= 3.2649999856948853) {
                        if (input[17] <= -0.03499999921768904) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9900695134061569, 0.009930486593843098}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[7] <= 5.965000152587891) {
                    if (input[2] <= 55.704999923706055) {
                        if (input[1] <= 25.550000190734863) {
                            { double _tmp[] = {0.375, 0.625}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.6838940978050232) {
                            { double _tmp[] = {0.9535864978902954, 0.046413502109704644}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6363636363636364, 0.36363636363636365}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 95.48330307006836) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[9] <= 20.03707504272461) {
            if (input[2] <= 43.53500175476074) {
                if (input[11] <= 9.68267011642456) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[6] <= 24.725000381469727) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[3] <= 558.4300231933594) {
                if (input[21] <= 0.5) {
                    if (input[4] <= 13.710000038146973) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[4] <= 13.740000247955322) {
                            { double _tmp[] = {0.25, 0.75}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 95.07178497314453) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[6] <= 21.760000228881836) {
                    if (input[15] <= 0.6386547684669495) {
                        if (input[16] <= 3.774999976158142) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[21] <= 0.5) {
                        if (input[8] <= 29.714731216430664) {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.008064516129032258, 0.9919354838709677}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 17.11944007873535) {
                            { double _tmp[] = {0.625, 0.375}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.38461538461538464, 0.6153846153846154}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var17, var24, 2, var16);
    double var25[2];
    if (input[19] <= 0.5) {
        if (input[5] <= 42.579999923706055) {
            if (input[9] <= 19.993428230285645) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[6] <= 24.27500057220459) {
                    if (input[8] <= 94.98890686035156) {
                        if (input[3] <= 506.0899963378906) {
                            { double _tmp[] = {0.017543859649122806, 0.9824561403508771}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[16] <= 3.34499990940094) {
                        if (input[2] <= 40.1299991607666) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.1, 0.9}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 95.03081893920898) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[5] <= 45.44499969482422) {
                if (input[12] <= -0.12940952181816096) {
                    if (input[11] <= 16.659059524536133) {
                        if (input[16] <= 3.1450001001358032) {
                            { double _tmp[] = {0.5217391304347826, 0.4782608695652174}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3129251700680272, 0.6870748299319728}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.834999918937683) {
                            { double _tmp[] = {0.7152317880794702, 0.2847682119205298}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 15.004252433776855) {
                        if (input[0] <= 11.5) {
                            { double _tmp[] = {0.9083333333333333, 0.09166666666666666}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6470588235294118, 0.35294117647058826}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[11] <= 18.706209182739258) {
                    if (input[9] <= 19.999879837036133) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.8823529411764706, 0.11764705882352941}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.015625, 0.984375}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[0] <= 13.5) {
                        if (input[9] <= 20.80477523803711) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.727184295654297) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[16] <= 3.40500009059906) {
            if (input[1] <= 16.755000114440918) {
                if (input[11] <= 9.600542068481445) {
                    if (input[16] <= 3.0049999952316284) {
                        if (input[8] <= 24.589221954345703) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[20] <= 0.5) {
                    if (input[7] <= 1.8600000143051147) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[8] <= 94.97217178344727) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 24.72592830657959) {
                        if (input[8] <= 18.253607749938965) {
                            { double _tmp[] = {0.9983108108108109, 0.0016891891891891893}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[2] <= 82.91999816894531) {
                if (input[10] <= 12.101587295532227) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[15] <= 0.7564300000667572) {
                        if (input[12] <= 0.9159756004810333) {
                            { double _tmp[] = {0.9552238805970149, 0.04477611940298507}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5833333333333334, 0.4166666666666667}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var16, var25, 2, var15);
    double var26[2];
    if (input[4] <= 8.265000343322754) {
        if (input[13] <= -0.00000000000000006123233601181349) {
            if (input[10] <= 18.80188751220703) {
                if (input[17] <= 0.695000022649765) {
                    if (input[15] <= 0.9926016330718994) {
                        if (input[2] <= 56.685001373291016) {
                            { double _tmp[] = {0.863013698630137, 0.136986301369863}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4, 0.6}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 15.861716270446777) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.09080982208252) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[6] <= 25.229999542236328) {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[11] <= 23.21647357940674) {
                    if (input[1] <= 32.209999084472656) {
                        if (input[1] <= 26.725000381469727) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9519650655021834, 0.048034934497816595}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 20.3323917388916) {
                            { double _tmp[] = {0.8103448275862069, 0.1896551724137931}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.975609756097561, 0.024390243902439025}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[8] <= 33.6677188873291) {
                if (input[20] <= 0.5) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[11] <= 8.851510524749756) {
                        if (input[12] <= -0.7329629063606262) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 22.71557903289795) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.995475113122172, 0.004524886877828055}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[20] <= 0.5) {
                    if (input[8] <= 94.99926376342773) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[2] <= 68.73500061035156) {
                        if (input[6] <= 16.260000228881836) {
                            { double _tmp[] = {0.9736842105263158, 0.02631578947368421}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[12] <= -0.12940952181816096) {
            if (input[11] <= 16.53276538848877) {
                if (input[4] <= 13.605000019073486) {
                    if (input[8] <= 95.0388298034668) {
                        if (input[5] <= 36.364999771118164) {
                            { double _tmp[] = {0.8695652173913043, 0.13043478260869565}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4542124542124542, 0.5457875457875457}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[8] <= 94.96247482299805) {
                        if (input[14] <= 0.44050246477127075) {
                            { double _tmp[] = {0.45454545454545453, 0.5454545454545454}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.1568627450980392, 0.8431372549019608}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[12] <= -0.379409521818161) {
                    if (input[0] <= 14.5) {
                        if (input[9] <= 20.038982391357422) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 67.86999893188477) {
                            { double _tmp[] = {0.6878612716763006, 0.31213872832369943}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[15] <= -0.997593343257904) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[10] <= 22.79732894897461) {
                            { double _tmp[] = {0.6470588235294118, 0.35294117647058826}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9354838709677419, 0.06451612903225806}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[4] <= 14.925000190734863) {
                if (input[4] <= 13.570000171661377) {
                    if (input[7] <= 3.5600000619888306) {
                        if (input[4] <= 11.565000057220459) {
                            { double _tmp[] = {0.9959677419354839, 0.004032258064516129}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9697802197802198, 0.03021978021978022}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 20.068065643310547) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 25.230002403259277) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9032258064516129, 0.0967741935483871}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[13] <= -0.9829629063606262) {
                    if (input[15] <= -0.2428407296538353) {
                        if (input[17] <= 17.40000057220459) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.8977101147174835) {
                            { double _tmp[] = {0.4716981132075472, 0.5283018867924528}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.1111111111111111, 0.8888888888888888}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 0.6850000023841858) {
                        if (input[17] <= 17.56999969482422) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9130434782608695, 0.08695652173913043}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 24.020000457763672) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var15, var26, 2, var14);
    double var27[2];
    if (input[2] <= 61.90500068664551) {
        if (input[13] <= -0.379409521818161) {
            if (input[0] <= 11.5) {
                if (input[16] <= 3.375) {
                    if (input[8] <= 94.2735824584961) {
                        if (input[10] <= 12.272700786590576) {
                            { double _tmp[] = {0.9411764705882353, 0.058823529411764705}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.6850000023841858) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.196990966796875) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[6] <= 20.539999961853027) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.21428571428571427, 0.7857142857142857}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[4] <= 12.045000076293945) {
                    if (input[5] <= 40.85499954223633) {
                        if (input[1] <= 27.934999465942383) {
                            { double _tmp[] = {0.7962962962962963, 0.2037037037037037}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5121951219512195, 0.4878048780487805}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= -0.9159756004810333) {
                            { double _tmp[] = {0.9714285714285714, 0.02857142857142857}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6602564102564102, 0.33974358974358976}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[14] <= 0.038721922785043716) {
                        if (input[15] <= 0.9999259114265442) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.890625, 0.109375}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3547794117647059, 0.6452205882352942}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[1] <= 24.744999885559082) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[9] <= 19.980029106140137) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[14] <= 0.9838904142379761) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.5909090909090909, 0.4090909090909091}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.012658227848101266, 0.9873417721518988}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[1] <= 33.15999984741211) {
            if (input[5] <= 42.68000030517578) {
                if (input[5] <= 22.054999351501465) {
                    if (input[20] <= 0.5) {
                        if (input[1] <= 19.90499973297119) {
                            { double _tmp[] = {0.8085106382978723, 0.19148936170212766}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5428571428571428, 0.45714285714285713}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[0] <= 17.5) {
                        if (input[6] <= 15.940000057220459) {
                            { double _tmp[] = {0.5555555555555556, 0.4444444444444444}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9778239778239778, 0.022176022176022176}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[2] <= 64.58499908447266) {
                    if (input[5] <= 42.81500053405762) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 0.029999999329447746) {
                            { double _tmp[] = {0.8701298701298701, 0.12987012987012986}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.35714285714285715, 0.6428571428571429}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 70.88000106811523) {
                        if (input[14] <= -0.9174476861953735) {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 18.546733856201172) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[8] <= 2.173766613006592) {
                if (input[1] <= 34.16499900817871) {
                    if (input[16] <= 3.819999933242798) {
                        if (input[5] <= 40.98500061035156) {
                            { double _tmp[] = {0.9230769230769231, 0.07692307692307693}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[6] <= 30.605000495910645) {
                    if (input[14] <= -0.8674242198467255) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 19.945598602294922) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 22.966288566589355) {
                        if (input[6] <= 31.045000076293945) {
                            { double _tmp[] = {0.9642857142857143, 0.03571428571428571}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7142857142857143, 0.2857142857142857}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 14.012845039367676) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var14, var27, 2, var13);
    double var28[2];
    if (input[3] <= 176.95499420166016) {
        if (input[2] <= 58.209999084472656) {
            if (input[10] <= 22.60922145843506) {
                if (input[2] <= 44.39500045776367) {
                    if (input[9] <= 19.777429580688477) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[0] <= 17.5) {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[13] <= 0.12940952181816093) {
                        if (input[17] <= 0.19500000029802322) {
                            { double _tmp[] = {0.7027027027027027, 0.2972972972972973}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8342857142857143, 0.1657142857142857}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= -0.5900000035762787) {
                            { double _tmp[] = {0.7954545454545454, 0.20454545454545456}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.98989898989899, 0.010101010101010102}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[15] <= 0.9999259114265442) {
                if (input[9] <= 19.98789691925049) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[11] <= 15.21347188949585) {
                        if (input[8] <= 94.98506927490234) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 15.333078861236572) {
                            { double _tmp[] = {0.16666666666666666, 0.8333333333333334}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[11] <= 9.04597806930542) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[0] <= 11.5) {
            if (input[17] <= 17.885000228881836) {
                if (input[0] <= 7.5) {
                    if (input[3] <= 177.3249969482422) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[5] <= 37.64500045776367) {
                        if (input[10] <= 24.5366849899292) {
                            { double _tmp[] = {0.9954022988505747, 0.004597701149425287}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 93.4094123840332) {
                            { double _tmp[] = {0.9776876267748479, 0.02231237322515213}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7083333333333334, 0.2916666666666667}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 58.198354721069336) {
                    if (input[15] <= 0.9999259114265442) {
                        if (input[5] <= 43.14500045776367) {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[2] <= 53.94999885559082) {
                        if (input[17] <= 18.880000114440918) {
                            { double _tmp[] = {0.21428571428571427, 0.7857142857142857}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[3] <= 629.4949951171875) {
                            { double _tmp[] = {0.9393939393939394, 0.06060606060606061}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5454545454545454, 0.45454545454545453}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[1] <= 30.964999198913574) {
                if (input[4] <= 14.984999656677246) {
                    if (input[0] <= 12.5) {
                        if (input[11] <= 14.048686504364014) {
                            { double _tmp[] = {0.5666666666666667, 0.43333333333333335}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.864406779661017, 0.13559322033898305}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.000791549682617) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2569060773480663, 0.7430939226519337}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[14] <= 0.060211045667529106) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[2] <= 61.03000068664551) {
                            { double _tmp[] = {0.25757575757575757, 0.7424242424242424}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8571428571428571, 0.14285714285714285}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[16] <= 3.7649999856948853) {
                    if (input[13] <= -0.9159756004810333) {
                        if (input[16] <= 2.634999990463257) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8702290076335878, 0.1297709923664122}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.019936561584473) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 44.96999931335449) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 20.440793991088867) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var13, var28, 2, var12);
    double var29[2];
    if (input[4] <= 8.265000343322754) {
        if (input[15] <= 0.9999259114265442) {
            if (input[9] <= 19.99619960784912) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[11] <= 15.301836013793945) {
                    if (input[13] <= -0.00000000000000006123233601181349) {
                        if (input[9] <= 30.709625244140625) {
                            { double _tmp[] = {0.1694915254237288, 0.8305084745762712}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8936170212765957, 0.10638297872340426}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 0.9150000214576721) {
                            { double _tmp[] = {0.8065693430656934, 0.19343065693430658}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.45454545454545453, 0.5454545454545454}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[21] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[10] <= 12.770171165466309) {
                if (input[10] <= 12.269398212432861) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[1] <= 18.55500030517578) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[5] <= 25.535000801086426) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[17] <= 2.3749999441206455) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[2] <= 60.10499954223633) {
            if (input[0] <= 11.5) {
                if (input[17] <= 18.144999504089355) {
                    if (input[3] <= 595.1050109863281) {
                        if (input[2] <= 57.82000160217285) {
                            { double _tmp[] = {0.9921875, 0.0078125}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9444444444444444, 0.05555555555555555}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[3] <= 604.7149963378906) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[3] <= 567.6000061035156) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[4] <= 14.87999963760376) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7592592592592593, 0.24074074074074073}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[3] <= 443.22999572753906) {
                    if (input[0] <= 13.5) {
                        if (input[16] <= 2.8149999380111694) {
                            { double _tmp[] = {0.8, 0.2}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 27.559999465942383) {
                            { double _tmp[] = {0.8888888888888888, 0.1111111111111111}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5882352941176471, 0.4117647058823529}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[8] <= 94.99789428710938) {
                            { double _tmp[] = {0.16666666666666666, 0.8333333333333334}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 26.97499942779541) {
                            { double _tmp[] = {0.34097421203438394, 0.6590257879656161}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[6] <= 29.484999656677246) {
                if (input[14] <= 0.051617756485939026) {
                    if (input[12] <= -0.379409521818161) {
                        if (input[1] <= 32.69499969482422) {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 79.52499771118164) {
                            { double _tmp[] = {0.9970414201183432, 0.0029585798816568047}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9230769230769231, 0.07692307692307693}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[12] <= -0.12940952181816096) {
                        if (input[0] <= 14.5) {
                            { double _tmp[] = {0.3548387096774194, 0.6451612903225806}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7058823529411765, 0.29411764705882354}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= -0.9829629063606262) {
                            { double _tmp[] = {0.803921568627451, 0.19607843137254902}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9728033472803347, 0.027196652719665274}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[0] <= 13.5) {
                    if (input[8] <= 37.703529357910156) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[14] <= -0.8840347826480865) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8333333333333334, 0.16666666666666666}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[15] <= -0.3737058788537979) {
                        if (input[9] <= 19.998269081115723) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var12, var29, 2, var11);
    double var30[2];
    if (input[18] <= 0.5) {
        if (input[16] <= 3.2450000047683716) {
            if (input[0] <= 18.5) {
                if (input[20] <= 0.5) {
                    if (input[10] <= 15.843462944030762) {
                        if (input[5] <= 16.875) {
                            { double _tmp[] = {0.25, 0.75}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8604651162790697, 0.13953488372093023}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.5894883573055267) {
                            { double _tmp[] = {0.2727272727272727, 0.7272727272727273}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[1] <= 24.300000190734863) {
                        if (input[19] <= 0.5) {
                            { double _tmp[] = {0.9932885906040269, 0.006711409395973154}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 24.3149995803833) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9084507042253521, 0.09154929577464789}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[16] <= 3.1149998903274536) {
                    if (input[9] <= 20.347567558288574) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[14] <= 0.2911748681217432) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 63.130001068115234) {
                        if (input[9] <= 34.00278091430664) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[2] <= 78.31500244140625) {
                if (input[7] <= 0.679999977350235) {
                    if (input[5] <= 29.360000610351562) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[21] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[11] <= 8.790648460388184) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9295774647887324, 0.07042253521126761}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[7] <= 4.480000019073486) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[17] <= -0.6100000143051147) {
                        if (input[6] <= 18.015000343322754) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[0] <= 11.5) {
            if (input[14] <= 0.9969919323921204) {
                if (input[4] <= 14.914999961853027) {
                    if (input[10] <= 18.448566436767578) {
                        if (input[16] <= 3.9950000047683716) {
                            { double _tmp[] = {0.9801980198019802, 0.019801980198019802}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8787878787878788, 0.12121212121212122}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 40.46500015258789) {
                            { double _tmp[] = {0.9977272727272727, 0.0022727272727272726}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9858490566037735, 0.014150943396226415}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 44.885000228881836) {
                        if (input[1] <= 25.809999465942383) {
                            { double _tmp[] = {0.9130434782608695, 0.08695652173913043}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.14285714285714285, 0.8571428571428571}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.6750000715255737) {
                            { double _tmp[] = {0.9, 0.1}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[3] <= 615.5950012207031) {
                    if (input[11] <= 10.909776210784912) {
                        if (input[10] <= 14.409997940063477) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[3] <= 163.5199966430664) {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9428571428571428, 0.05714285714285714}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[17] <= 13.555000305175781) {
                if (input[16] <= 2.465000033378601) {
                    if (input[10] <= 25.003520011901855) {
                        if (input[11] <= 19.98077392578125) {
                            { double _tmp[] = {0.8222222222222222, 0.17777777777777778}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.16666666666666666, 0.8333333333333334}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 44.59000015258789) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.875, 0.125}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[0] <= 13.5) {
                        if (input[14] <= -0.08596161380410194) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8666666666666667, 0.13333333333333333}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[3] <= 177.70999908447266) {
                            { double _tmp[] = {0.7738095238095238, 0.2261904761904762}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5663716814159292, 0.4336283185840708}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[0] <= 12.5) {
                    if (input[4] <= 14.934999942779541) {
                        if (input[14] <= 0.8474703133106232) {
                            { double _tmp[] = {0.9130434782608695, 0.08695652173913043}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.26666666666666666, 0.7333333333333333}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 48.03499984741211) {
                            { double _tmp[] = {0.5405405405405406, 0.4594594594594595}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.125, 0.875}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 94.96777725219727) {
                        if (input[2] <= 39.869998931884766) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.22608695652173913, 0.7739130434782608}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var11, var30, 2, var10);
    double var31[2];
    if (input[18] <= 0.5) {
        if (input[1] <= 24.714999198913574) {
            if (input[16] <= 3.1850000619888306) {
                if (input[15] <= 0.9999259114265442) {
                    if (input[9] <= 22.466665267944336) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 2.524999976158142) {
                            { double _tmp[] = {0.05263157894736842, 0.9473684210526315}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.898876404494382, 0.10112359550561797}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 17.979999542236328) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[8] <= 94.98286056518555) {
                    if (input[20] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[20] <= 0.5) {
                if (input[2] <= 81.49500274658203) {
                    if (input[11] <= 11.08434009552002) {
                        if (input[17] <= 0.26500000059604645) {
                            { double _tmp[] = {0.09090909090909091, 0.9090909090909091}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 95.05762100219727) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[6] <= 22.105000495910645) {
                    if (input[13] <= 0.12940952181816104) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 19.97025489807129) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[12] <= -0.9159756004810333) {
                            { double _tmp[] = {0.04, 0.96}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[9] <= 19.999879837036133) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[9] <= 24.664756774902344) {
                if (input[2] <= 40.06999969482422) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[2] <= 71.09000015258789) {
                        if (input[0] <= 7.5) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.01800327332242226, 0.9819967266775778}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.0299999713897705) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[11] <= 15.305103302001953) {
                    if (input[21] <= 0.5) {
                        if (input[2] <= 40.005001068115234) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 55.78692054748535) {
                            { double _tmp[] = {0.9038461538461539, 0.09615384615384616}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[3] <= 283.9650115966797) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[0] <= 14.5) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var10, var31, 2, var9);
    double var32[2];
    if (input[9] <= 19.999879837036133) {
        { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
    } else {
        if (input[1] <= 26.335000038146973) {
            if (input[5] <= 42.935001373291016) {
                if (input[15] <= 0.7755672037601471) {
                    if (input[8] <= 94.99926376342773) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[6] <= 21.170000076293945) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[11] <= 11.89447021484375) {
                        if (input[1] <= 26.31999969482422) {
                            { double _tmp[] = {0.058823529411764705, 0.9411764705882353}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[14] <= 0.5270728468894958) {
                if (input[11] <= 9.542153358459473) {
                    if (input[6] <= 24.390000343322754) {
                        if (input[3] <= 229.93999481201172) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.625, 0.375}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[4] <= 13.680000305175781) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[4] <= 13.730000019073486) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[16] <= 4.365000009536743) {
                    if (input[20] <= 0.5) {
                        if (input[6] <= 26.135000228881836) {
                            { double _tmp[] = {0.9690721649484536, 0.030927835051546393}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= 0.6050504744052887) {
                            { double _tmp[] = {0.24390243902439024, 0.7560975609756098}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0035335689045936395, 0.9964664310954063}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 94.98920822143555) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var9, var32, 2, var8);
    double var33[2];
    if (input[1] <= 26.574999809265137) {
        if (input[9] <= 20.045254707336426) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[6] <= 20.335000038146973) {
                if (input[8] <= 94.98627853393555) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[21] <= 0.5) {
                    if (input[2] <= 40.224998474121094) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[8] <= 94.99501037597656) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[11] <= 14.191235542297363) {
            if (input[9] <= 19.99622631072998) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[14] <= 0.7176503241062164) {
                    if (input[2] <= 40.01499938964844) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[15] <= -0.8088971376419067) {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[15] <= 0.5343527793884277) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.8181818181818182, 0.18181818181818182}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.03763440860215054, 0.9623655913978495}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 25.41837215423584) {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9452054794520548, 0.0547945205479452}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[2] <= 62.885000228881836) {
                if (input[12] <= -0.12940952181816096) {
                    if (input[16] <= 2.284999966621399) {
                        if (input[9] <= 19.932077407836914) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4444444444444444, 0.5555555555555556}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= -0.7865660786628723) {
                            { double _tmp[] = {0.4925373134328358, 0.5074626865671642}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7095115681233933, 0.29048843187660667}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 61.730337142944336) {
                        if (input[17] <= 17.550000190734863) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 20.30668830871582) {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.42857142857142855, 0.5714285714285714}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[1] <= 33.69499969482422) {
                    if (input[3] <= 511.00999450683594) {
                        if (input[17] <= 16.079999923706055) {
                            { double _tmp[] = {0.9830508474576272, 0.01694915254237288}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[12] <= -0.12940952181816096) {
                            { double _tmp[] = {0.25, 0.75}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9130434782608695, 0.08695652173913043}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 26.59354877471924) {
                        if (input[9] <= 20.294532775878906) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 64.70000076293945) {
                            { double _tmp[] = {0.16666666666666666, 0.8333333333333334}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5454545454545454, 0.45454545454545453}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var8, var33, 2, var7);
    double var34[2];
    if (input[17] <= 13.204999923706055) {
        if (input[1] <= 26.744999885559082) {
            if (input[16] <= 3.415000081062317) {
                if (input[2] <= 49.095001220703125) {
                    if (input[16] <= 2.9550000429153442) {
                        if (input[15] <= 0.9828854203224182) {
                            { double _tmp[] = {0.7222222222222222, 0.2777777777777778}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.07142857142857142, 0.9285714285714286}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 24.47312641143799) {
                        if (input[17] <= -0.8949999809265137) {
                            { double _tmp[] = {0.9929577464788732, 0.007042253521126761}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9992816091954023, 0.0007183908045977011}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9104477611940298, 0.08955223880597014}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 94.98669815063477) {
                    if (input[9] <= 26.294711112976074) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[13] <= -0.1294095218181611) {
                if (input[2] <= 62.885000228881836) {
                    if (input[5] <= 36.60000038146973) {
                        if (input[3] <= 154.1699981689453) {
                            { double _tmp[] = {0.88, 0.12}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7058823529411765, 0.29411764705882354}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= -0.9159756004810333) {
                            { double _tmp[] = {0.9508196721311475, 0.04918032786885246}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5950226244343891, 0.40497737556561086}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[1] <= 33.86000061035156) {
                        if (input[5] <= 31.234999656677246) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9679802955665024, 0.03201970443349754}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.914523124694824) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[5] <= 27.84000015258789) {
                    if (input[9] <= 19.984943389892578) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[16] <= 2.6200000047683716) {
                            { double _tmp[] = {0.058823529411764705, 0.9411764705882353}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[1] <= 31.795000076293945) {
                        if (input[15] <= 0.4745113253593445) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.2}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 30.5) {
                            { double _tmp[] = {0.9545454545454546, 0.045454545454545456}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[0] <= 11.5) {
            if (input[3] <= 595.7649841308594) {
                if (input[2] <= 45.540000915527344) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[15] <= 0.9997037053108215) {
                        if (input[8] <= 93.30538940429688) {
                            { double _tmp[] = {0.9842271293375394, 0.015772870662460567}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8863636363636364, 0.11363636363636363}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.8450000286102295) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[3] <= 600.7049865722656) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[4] <= 15.864999771118164) {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.6904761904761905, 0.30952380952380953}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[12] <= -0.12940952181816096) {
                if (input[20] <= 0.5) {
                    if (input[8] <= 94.98316192626953) {
                        if (input[6] <= 25.079999923706055) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[14] <= 0.21772121638059616) {
                        if (input[9] <= 20.093460083007812) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.16666666666666666, 0.8333333333333334}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 9.667775630950928) {
                            { double _tmp[] = {0.8888888888888888, 0.1111111111111111}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.30094043887147337, 0.6990595611285266}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 20.079090118408203) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[17] <= 21.329999923706055) {
                        if (input[7] <= 0.7999999821186066) {
                            { double _tmp[] = {0.11594202898550725, 0.8840579710144928}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7777777777777778, 0.2222222222222222}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var7, var34, 2, var6);
    double var35[2];
    if (input[17] <= 8.724999904632568) {
        if (input[1] <= 32.60499954223633) {
            if (input[2] <= 58.19499969482422) {
                if (input[13] <= 0.12940952181816093) {
                    if (input[5] <= 25.505000114440918) {
                        if (input[16] <= 2.6799999475479126) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2, 0.8}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 24.11500072479248) {
                            { double _tmp[] = {0.9358974358974359, 0.0641025641025641}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8200836820083682, 0.1799163179916318}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 44.69000053405762) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[8] <= 94.16705322265625) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.875, 0.125}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 20.005657196044922) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[7] <= 1.5849999785423279) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[15] <= -0.8520459532737732) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8857142857142857, 0.11428571428571428}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[5] <= 36.385000228881836) {
                if (input[1] <= 32.73000144958496) {
                    if (input[3] <= 98.83500289916992) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[16] <= 2.7949999570846558) {
                    if (input[11] <= 19.368399620056152) {
                        if (input[8] <= 21.935863494873047) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7142857142857143, 0.2857142857142857}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 32.84000015258789) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9148936170212766, 0.0851063829787234}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 41.16499900817871) {
                        if (input[11] <= 22.308323860168457) {
                            { double _tmp[] = {0.6808510638297872, 0.3191489361702128}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 25.09012222290039) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.18181818181818182, 0.8181818181818182}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[14] <= -0.017212719190865755) {
            if (input[1] <= 33.27499961853027) {
                if (input[9] <= 20.13831329345703) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[0] <= 13.5) {
                    if (input[6] <= 30.570000648498535) {
                        if (input[14] <= -0.5439483821392059) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[4] <= 11.125) {
                        if (input[5] <= 44.779998779296875) {
                            { double _tmp[] = {0.6818181818181818, 0.3181818181818182}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 11.724999904632568) {
                            { double _tmp[] = {0.23076923076923078, 0.7692307692307693}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[5] <= 43.26999855041504) {
                if (input[0] <= 12.5) {
                    if (input[4] <= 14.87999963760376) {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.9864864864864865, 0.013513513513513514}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9615384615384616, 0.038461538461538464}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 20.002517700195312) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[8] <= 95.02390670776367) {
                            { double _tmp[] = {0.03571428571428571, 0.9642857142857143}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[2] <= 60.16499900817871) {
                    if (input[12] <= 0.12940952181816107) {
                        if (input[8] <= 94.96777725219727) {
                            { double _tmp[] = {0.3726851851851852, 0.6273148148148148}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.16499999910593033) {
                            { double _tmp[] = {0.9074074074074074, 0.09259259259259259}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6538461538461539, 0.34615384615384615}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[15] <= -0.85642409324646) {
                        if (input[9] <= 20.17798614501953) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.194307327270508) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2564102564102564, 0.7435897435897436}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var6, var35, 2, var5);
    double var36[2];
    if (input[1] <= 26.704999923706055) {
        if (input[3] <= 595.1099853515625) {
            if (input[8] <= 94.68511199951172) {
                if (input[16] <= 3.3649998903274536) {
                    if (input[8] <= 50.29384803771973) {
                        if (input[8] <= 50.25643539428711) {
                            { double _tmp[] = {0.9665551839464883, 0.033444816053511704}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9962264150943396, 0.0037735849056603774}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[20] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[14] <= 0.10308642312884331) {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9357798165137615, 0.06422018348623854}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[2] <= 55.10499954223633) {
                    if (input[4] <= 6.684999942779541) {
                        if (input[8] <= 95.04730987548828) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 14.954760074615479) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 16.190826416015625) {
                        if (input[0] <= 2.5) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9347826086956522, 0.06521739130434782}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 95.00066375732422) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[13] <= -0.9829629063606262) {
                if (input[16] <= 4.080000162124634) {
                    if (input[1] <= 26.670000076293945) {
                        if (input[9] <= 19.720837593078613) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[9] <= 20.26059055328369) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[9] <= 49.63025093078613) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[2] <= 62.170000076293945) {
            if (input[9] <= 20.00141429901123) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[16] <= 4.370000123977661) {
                    if (input[20] <= 0.5) {
                        if (input[1] <= 26.934999465942383) {
                            { double _tmp[] = {0.25, 0.75}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8651685393258427, 0.1348314606741573}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 13.746639728546143) {
                            { double _tmp[] = {0.6923076923076923, 0.3076923076923077}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.025878003696857672, 0.9741219963031423}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 61.81999969482422) {
                        if (input[5] <= 45.61000061035156) {
                            { double _tmp[] = {0.972972972972973, 0.02702702702702703}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7692307692307693, 0.23076923076923078}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[5] <= 43.90500068664551) {
                if (input[9] <= 20.04786968231201) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[8] <= 90.19352340698242) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[6] <= 23.09000015258789) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[9] <= 20.186522483825684) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[8] <= 95.06401824951172) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var5, var36, 2, var4);
    double var37[2];
    if (input[9] <= 19.999879837036133) {
        { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
    } else {
        if (input[9] <= 24.664756774902344) {
            if (input[3] <= 49.21500015258789) {
                if (input[15] <= 0.702111154794693) {
                    if (input[4] <= 2.75) {
                        if (input[8] <= 56.82386112213135) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 27.774999618530273) {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[7] <= 1.3550000190734863) {
                    if (input[2] <= 40.07499885559082) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 0.5249999761581421) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.013157894736842105, 0.9868421052631579}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 41.724998474121094) {
                        if (input[8] <= 94.89779281616211) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= 0.7456779479980469) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[14] <= 0.523396223783493) {
                if (input[4] <= 8.164999961853027) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[10] <= 12.799055576324463) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[10] <= 14.54003620147705) {
                    if (input[6] <= 12.679999828338623) {
                        if (input[17] <= 0.13999999687075615) {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 94.9368667602539) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 94.99821853637695) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var4, var37, 2, var3);
    double var38[2];
    if (input[2] <= 57.97500038146973) {
        if (input[5] <= 36.72500038146973) {
            if (input[2] <= 45.97500038146973) {
                if (input[16] <= 3.274999976158142) {
                    if (input[9] <= 19.990093231201172) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[2] <= 40.84000015258789) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 12.542826175689697) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[15] <= 0.9996296167373657) {
                    if (input[14] <= 0.459728479385376) {
                        if (input[2] <= 50.13999938964844) {
                            { double _tmp[] = {0.9615384615384616, 0.038461538461538464}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 35.560001373291016) {
                            { double _tmp[] = {0.9051724137931034, 0.09482758620689655}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6470588235294118, 0.35294117647058826}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[0] <= 18.5) {
                        if (input[16] <= 2.8450000286102295) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[8] <= 95.0129508972168) {
                if (input[0] <= 11.5) {
                    if (input[16] <= 4.180000066757202) {
                        if (input[14] <= 0.9873128533363342) {
                            { double _tmp[] = {0.9696969696969697, 0.030303030303030304}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4, 0.6}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 50.44804000854492) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 20.806547164916992) {
                        if (input[5] <= 45.52499961853027) {
                            { double _tmp[] = {0.39436619718309857, 0.6056338028169014}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.21511627906976744, 0.7848837209302325}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 65.60124206542969) {
                            { double _tmp[] = {0.734375, 0.265625}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2857142857142857, 0.7142857142857143}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
            }
        }
    } else {
        if (input[20] <= 0.5) {
            if (input[0] <= 7.5) {
                if (input[8] <= 94.98286056518555) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[8] <= 94.97827911376953) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[1] <= 28.984999656677246) {
                if (input[9] <= 20.246374130249023) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[21] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[2] <= 64.09500122070312) {
                            { double _tmp[] = {0.375, 0.625}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 62.78841781616211) {
                    if (input[3] <= 106.68000030517578) {
                        if (input[1] <= 32.35999870300293) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9193548387096774, 0.08064516129032258}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[3] <= 290.9700012207031) {
                            { double _tmp[] = {0.6618705035971223, 0.3381294964028777}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8783505154639175, 0.12164948453608247}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 41.64500045776367) {
                        if (input[13] <= -0.1294095218181611) {
                            { double _tmp[] = {0.7307692307692307, 0.2692307692307692}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.999879837036133) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var3, var38, 2, var2);
    double var39[2];
    if (input[2] <= 58.864999771118164) {
        if (input[5] <= 43.35499954223633) {
            if (input[9] <= 20.00141429901123) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[8] <= 95.00228118896484) {
                    if (input[2] <= 40.15999984741211) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[9] <= 20.04690170288086) {
                if (input[11] <= 16.286739349365234) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[11] <= 16.296311378479004) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[15] <= 0.03011918906122446) {
                    if (input[9] <= 42.16575813293457) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 26.204371452331543) {
                        if (input[5] <= 44.69999885559082) {
                            { double _tmp[] = {0.18181818181818182, 0.8181818181818182}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.009433962264150943, 0.9905660377358491}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 11.424489498138428) {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[15] <= 0.9999259114265442) {
            if (input[13] <= -0.6035533845424652) {
                if (input[9] <= 20.0496768951416) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[8] <= 94.9574966430664) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[20] <= 0.5) {
                    if (input[14] <= 0.523396223783493) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9306122448979591, 0.06938775510204082}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.004352569580078) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[6] <= 27.329999923706055) {
                            { double _tmp[] = {0.725, 0.275}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[2] <= 67.90999984741211) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var2, var39, 2, var1);
    mul_vector_number(var1, 0.05, 2, var0);
    memcpy(output, var0, 2 * sizeof(double));
}
