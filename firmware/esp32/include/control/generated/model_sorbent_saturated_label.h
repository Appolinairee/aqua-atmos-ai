#pragma once

#include "control/generated/model_utils.h"

#include <string.h>


inline void predict_sorbent_saturated_label(const double * input, double * output) {
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
    if (input[5] <= 37.46500015258789) {
        if (input[1] <= 26.09500026702881) {
            if (input[2] <= 44.73500061035156) {
                if (input[10] <= 12.496838092803955) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[15] <= 0.9999259114265442) {
                    if (input[16] <= 4.704999923706055) {
                        if (input[9] <= 21.113862991333008) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9579288025889967, 0.042071197411003236}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 4.769999980926514) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[16] <= 3.534999966621399) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[5] <= 17.3100004196167) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[11] <= 10.543559551239014) {
                if (input[9] <= 20.04043197631836) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[9] <= 31.663076400756836) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[12] <= 0.9829629063606262) {
                    if (input[13] <= -0.1294095218181611) {
                        if (input[1] <= 28.714999198913574) {
                            { double _tmp[] = {0.9672897196261683, 0.03271028037383177}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8407643312101911, 0.1592356687898089}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 32.18499946594238) {
                            { double _tmp[] = {0.9953775038520801, 0.004622496147919877}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8823529411764706, 0.11764705882352941}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[9] <= 19.995314598083496) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[11] <= 15.415956974029541) {
                if (input[9] <= 27.048574447631836) {
                    if (input[2] <= 49.85000038146973) {
                        if (input[10] <= 17.680761337280273) {
                            { double _tmp[] = {0.006756756756756757, 0.9932432432432432}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[0] <= 13.5) {
                            { double _tmp[] = {0.13043478260869565, 0.8695652173913043}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4496124031007752, 0.5503875968992248}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 13.834977626800537) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[17] <= 15.130000114440918) {
                            { double _tmp[] = {0.8163265306122449, 0.1836734693877551}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9560439560439561, 0.04395604395604396}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[21] <= 0.5) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[14] <= 0.6419596076011658) {
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
            if (input[7] <= 0.9950000047683716) {
                if (input[9] <= 20.00054359436035) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
        }
    } else {
        if (input[10] <= 25.04183864593506) {
            if (input[3] <= 426.4350128173828) {
                if (input[9] <= 20.004352569580078) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[6] <= 25.34000015258789) {
                        if (input[15] <= 0.9304805099964142) {
                            { double _tmp[] = {0.9808306709265175, 0.019169329073482427}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6153846153846154, 0.38461538461538464}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 90.8923568725586) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[12] <= -0.12940952181816096) {
                    if (input[2] <= 63.61000061035156) {
                        if (input[12] <= -0.379409521818161) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5833333333333334, 0.4166666666666667}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 23.90555191040039) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.363150596618652) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.125, 0.875}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8181818181818182, 0.18181818181818182}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[4] <= 7.0350000858306885) {
                if (input[9] <= 19.97025489807129) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[10] <= 26.798433303833008) {
                    if (input[9] <= 20.12176513671875) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[0] <= 13.5) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 20.31127643585205) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var20, var21, 2, var19);
    double var22[2];
    if (input[5] <= 36.28000068664551) {
        if (input[2] <= 49.02499961853027) {
            if (input[4] <= 7.789999961853027) {
                if (input[9] <= 20.052138328552246) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[7] <= 0.8600000143051147) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[10] <= 14.850748538970947) {
                    if (input[17] <= 4.860000133514404) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[6] <= 24.40999984741211) {
                            { double _tmp[] = {0.35714285714285715, 0.6428571428571429}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9, 0.1}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 82.71437072753906) {
                        if (input[9] <= 20.31787395477295) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[13] <= -0.00000000000000006123233601181349) {
                if (input[14] <= -0.9275073111057281) {
                    if (input[1] <= 32.47999954223633) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[11] <= 21.821735382080078) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[1] <= 26.744999885559082) {
                        if (input[14] <= 0.8382719457149506) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9767441860465116, 0.023255813953488372}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.9603658536585366, 0.039634146341463415}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8241758241758241, 0.17582417582417584}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[7] <= 0.6550000011920929) {
                    if (input[6] <= 16.585000038146973) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[5] <= 45.625) {
            if (input[2] <= 45.795000076293945) {
                if (input[10] <= 15.703934669494629) {
                    if (input[17] <= 17.5649995803833) {
                        if (input[12] <= -0.12940952181816096) {
                            { double _tmp[] = {0.08695652173913043, 0.9130434782608695}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= 0.9123409688472748) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9, 0.1}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[7] <= 0.9950000047683716) {
                    if (input[9] <= 20.019936561584473) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[1] <= 29.329999923706055) {
                            { double _tmp[] = {0.4563106796116505, 0.5436893203883495}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.011299435028248588, 0.9887005649717514}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[16] <= 3.215000033378601) {
                if (input[7] <= 0.22499999403953552) {
                    if (input[8] <= 55.99243354797363) {
                        if (input[9] <= 19.990266799926758) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 47.21000099182129) {
                            { double _tmp[] = {0.13636363636363635, 0.8636363636363636}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[15] <= 0.8020229041576385) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[11] <= 12.108928203582764) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[10] <= 22.16209888458252) {
                    if (input[7] <= 0.925000011920929) {
                        if (input[9] <= 19.975358963012695) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.125, 0.875}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 20.264909744262695) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var19, var22, 2, var18);
    double var23[2];
    if (input[2] <= 61.375) {
        if (input[7] <= 0.9050000011920929) {
            if (input[0] <= 16.5) {
                if (input[9] <= 20.00141429901123) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[21] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[16] <= 3.7549999952316284) {
                            { double _tmp[] = {0.20618556701030927, 0.7938144329896907}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6741573033707865, 0.3258426966292135}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[20] <= 0.5) {
                    if (input[8] <= 94.98898315429688) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 19.990134239196777) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[13] <= -0.379409521818161) {
                if (input[14] <= 0.5416228175163269) {
                    if (input[9] <= 22.14533519744873) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[2] <= 52.67999839782715) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 0.9750000238418579) {
                        if (input[8] <= 34.50532627105713) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9230769230769231, 0.07692307692307693}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[6] <= 24.105000495910645) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[14] <= 0.6932555437088013) {
                        if (input[10] <= 15.263710021972656) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[9] <= 19.99996566772461) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[6] <= 26.15999984741211) {
                if (input[1] <= 25.9399995803833) {
                    if (input[12] <= 0.9829629063606262) {
                        if (input[13] <= 0.7865660786628723) {
                            { double _tmp[] = {0.9666666666666667, 0.03333333333333333}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 73.42288589477539) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[12] <= 0.12940952181816107) {
                        if (input[16] <= 4.010000109672546) {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 95.0971450805664) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 23.155884742736816) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[0] <= 13.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var18, var23, 2, var17);
    double var24[2];
    if (input[5] <= 42.875) {
        if (input[3] <= 106.88999938964844) {
            if (input[16] <= 4.920000076293945) {
                if (input[13] <= 0.12940952181816104) {
                    if (input[11] <= 9.111061096191406) {
                        if (input[14] <= 0.060211045667529106) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 3.9350000619888306) {
                            { double _tmp[] = {0.9704918032786886, 0.029508196721311476}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6, 0.4}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[7] <= 0.6800000071525574) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[12] <= -0.9159756004810333) {
                            { double _tmp[] = {0.9954545454545455, 0.004545454545454545}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[14] <= 0.8110581338405609) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[0] <= 13.5) {
                if (input[9] <= 20.140535354614258) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[9] <= 86.82854843139648) {
                            { double _tmp[] = {0.9615384615384616, 0.038461538461538464}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.3549998998641968) {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2, 0.8}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[14] <= 0.7206604778766632) {
                    if (input[8] <= 90.3223762512207) {
                        if (input[2] <= 40.35499954223633) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6361256544502618, 0.36387434554973824}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 11.706563472747803) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9705882352941176, 0.029411764705882353}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 14.989629745483398) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8582089552238806, 0.1417910447761194}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 20.324609756469727) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7027027027027027, 0.2972972972972973}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[12] <= -0.12940952181816096) {
            if (input[14] <= 0.012910176534205675) {
                if (input[13] <= -0.9159756004810333) {
                    if (input[9] <= 20.248677253723145) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[1] <= 33.739999771118164) {
                        if (input[5] <= 43.34499931335449) {
                            { double _tmp[] = {0.5833333333333334, 0.4166666666666667}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.24, 0.76}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 38.79018592834473) {
                            { double _tmp[] = {0.8181818181818182, 0.18181818181818182}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[3] <= 543.5999755859375) {
                    if (input[16] <= 4.180000066757202) {
                        if (input[6] <= 27.494999885559082) {
                            { double _tmp[] = {0.5572519083969466, 0.44274809160305345}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3978494623655914, 0.6021505376344086}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[21] <= 0.5) {
                        if (input[6] <= 26.269999504089355) {
                            { double _tmp[] = {0.1984126984126984, 0.8015873015873016}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7777777777777778, 0.2222222222222222}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= 0.9920752048492432) {
                            { double _tmp[] = {0.5094339622641509, 0.49056603773584906}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[15] <= 0.9645784497261047) {
                if (input[5] <= 45.71500015258789) {
                    if (input[11] <= 13.709824085235596) {
                        if (input[4] <= 14.429999828338623) {
                            { double _tmp[] = {0.4666666666666667, 0.5333333333333333}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8739495798319328, 0.12605042016806722}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 23.570000648498535) {
                            { double _tmp[] = {0.7777777777777778, 0.2222222222222222}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 16.177873611450195) {
                        if (input[8] <= 94.44416427612305) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 48.47500038146973) {
                            { double _tmp[] = {0.7701149425287356, 0.22988505747126436}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.16666666666666666, 0.8333333333333334}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[3] <= 637.7449951171875) {
                    if (input[9] <= 19.98655605316162) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    }
    add_vectors(var17, var24, 2, var16);
    double var25[2];
    if (input[19] <= 0.5) {
        if (input[5] <= 37.07500076293945) {
            if (input[9] <= 19.980996131896973) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[6] <= 25.229999542236328) {
                    if (input[8] <= 93.22002410888672) {
                        if (input[7] <= 1.0300000309944153) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.759999990463257) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9183673469387755, 0.08163265306122448}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[1] <= 29.660000801086426) {
                        if (input[11] <= 12.366337299346924) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.631578947368421, 0.3684210526315789}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[5] <= 45.44499969482422) {
                if (input[12] <= -0.12940952181816096) {
                    if (input[11] <= 10.292279720306396) {
                        if (input[4] <= 14.760000228881836) {
                            { double _tmp[] = {0.037037037037037035, 0.9629629629629629}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 4.369999885559082) {
                            { double _tmp[] = {0.6388101983002833, 0.3611898016997167}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 15.27344560623169) {
                        if (input[0] <= 11.5) {
                            { double _tmp[] = {0.9559228650137741, 0.0440771349862259}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7192982456140351, 0.2807017543859649}; memcpy(var25, _tmp, 2 * sizeof(double)); }
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
                            { double _tmp[] = {0.07291666666666667, 0.9270833333333334}; memcpy(var25, _tmp, 2 * sizeof(double)); }
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
            if (input[1] <= 19.914999961853027) {
                if (input[8] <= 21.27046489715576) {
                    if (input[11] <= 9.840669631958008) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[10] <= 16.63725185394287) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[13] <= 0.379409521818161) {
                            { double _tmp[] = {0.8947368421052632, 0.10526315789473684}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[9] <= 48.387887954711914) {
                if (input[15] <= 0.7564300000667572) {
                    if (input[2] <= 84.06000137329102) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var16, var25, 2, var15);
    double var26[2];
    if (input[4] <= 8.28000020980835) {
        if (input[13] <= -0.00000000000000006123233601181349) {
            if (input[10] <= 14.831544876098633) {
                if (input[14] <= 0.18819881975650787) {
                    if (input[2] <= 54.52499961853027) {
                        if (input[5] <= 32.71499824523926) {
                            { double _tmp[] = {0.09090909090909091, 0.9090909090909091}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[5] <= 28.524999618530273) {
                        if (input[1] <= 26.109999656677246) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8333333333333334, 0.16666666666666666}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 14.174549102783203) {
                            { double _tmp[] = {0.2, 0.8}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8571428571428571, 0.14285714285714285}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[11] <= 23.21647357940674) {
                    if (input[15] <= 0.995192140340805) {
                        if (input[9] <= 19.98343276977539) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7009345794392523, 0.29906542056074764}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 49.10499954223633) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[6] <= 13.184999942779541) {
                if (input[6] <= 13.139999866485596) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[2] <= 44.69000053405762) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[8] <= 34.927947998046875) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.8571428571428571, 0.14285714285714285}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.9300000071525574) {
                            { double _tmp[] = {0.9947916666666666, 0.005208333333333333}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[12] <= -0.12940952181816096) {
            if (input[9] <= 20.012310028076172) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[3] <= 287.7799987792969) {
                    if (input[13] <= -0.379409521818161) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[8] <= 95.02977752685547) {
                        if (input[13] <= -0.9159756004810333) {
                            { double _tmp[] = {0.056074766355140186, 0.9439252336448598}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.19014084507042253, 0.8098591549295775}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[13] <= -0.9829629063606262) {
                if (input[9] <= 20.01204490661621) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[16] <= 3.834999918937683) {
                        if (input[8] <= 94.25262832641602) {
                            { double _tmp[] = {0.022727272727272728, 0.9772727272727273}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.16666666666666666, 0.8333333333333334}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9333333333333333, 0.06666666666666667}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[2] <= 57.790000915527344) {
                    if (input[8] <= 20.857736587524414) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[2] <= 57.65500068664551) {
                            { double _tmp[] = {0.9147727272727273, 0.08522727272727272}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2857142857142857, 0.7142857142857143}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[16] <= 4.6600000858306885) {
                        if (input[5] <= 44.30000114440918) {
                            { double _tmp[] = {0.98856416772554, 0.011435832274459974}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9056603773584906, 0.09433962264150944}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[4] <= 11.950000286102295) {
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
    if (input[2] <= 60.84000015258789) {
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
                            { double _tmp[] = {0.2222222222222222, 0.7777777777777778}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[10] <= 14.968957424163818) {
                    if (input[16] <= 2.6049998998641968) {
                        if (input[15] <= 0.9801423251628876) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= -0.9829629063606262) {
                            { double _tmp[] = {0.6071428571428571, 0.39285714285714285}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.12389380530973451, 0.8761061946902655}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 0.9950000047683716) {
                        if (input[16] <= 4.585000038146973) {
                            { double _tmp[] = {0.49709302325581395, 0.502906976744186}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[7] <= 0.5949999988079071) {
                if (input[20] <= 0.5) {
                    if (input[16] <= 4.234999895095825) {
                        if (input[1] <= 27.985000610351562) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= 0.7856207489967346) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 44.385000228881836) {
                        if (input[5] <= 28.75) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4, 0.6}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 37.61000061035156) {
                            { double _tmp[] = {0.8711111111111111, 0.1288888888888889}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[5] <= 27.65999984741211) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[9] <= 20.34746742248535) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 0.8550000190734863) {
                            { double _tmp[] = {0.4444444444444444, 0.5555555555555556}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[6] <= 29.25) {
            if (input[5] <= 42.68000030517578) {
                if (input[12] <= 0.9159756004810333) {
                    if (input[17] <= 15.919999599456787) {
                        if (input[15] <= 0.9999259114265442) {
                            { double _tmp[] = {0.996996996996997, 0.003003003003003003}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8571428571428571, 0.14285714285714285}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[4] <= 13.570000171661377) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[14] <= 0.999657392501831) {
                        if (input[14] <= -0.8587321639060974) {
                            { double _tmp[] = {0.90625, 0.09375}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9901408450704225, 0.009859154929577466}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 2.200000047683716) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[5] <= 42.739999771118164) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[17] <= 16.125) {
                        if (input[6] <= 27.59000015258789) {
                            { double _tmp[] = {0.9836065573770492, 0.01639344262295082}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8064516129032258, 0.1935483870967742}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 16.210000038146973) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7936507936507936, 0.20634920634920634}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[9] <= 20.00290298461914) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var14, var27, 2, var13);
    double var28[2];
    if (input[3] <= 177.23999786376953) {
        if (input[2] <= 46.98000144958496) {
            if (input[8] <= 32.903724670410156) {
                { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[11] <= 9.555899143218994) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[9] <= 20.138513565063477) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[16] <= 3.634999990463257) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[5] <= 33.57500076293945) {
                if (input[20] <= 0.5) {
                    if (input[7] <= 0.6949999928474426) {
                        if (input[13] <= -0.1294095218181611) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 19.98789691925049) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[14] <= 0.7174376547336578) {
                            { double _tmp[] = {0.46153846153846156, 0.5384615384615384}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9069767441860465, 0.09302325581395349}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[5] <= 36.28000068664551) {
                    if (input[9] <= 19.929092407226562) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[16] <= 3.3249999284744263) {
                            { double _tmp[] = {0.08333333333333333, 0.9166666666666666}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 18.446036338806152) {
                        if (input[8] <= 54.310367584228516) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 25.263442993164062) {
                            { double _tmp[] = {0.7, 0.3}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[12] <= 0.12940952181816107) {
            if (input[7] <= 0.9950000047683716) {
                if (input[9] <= 20.001455307006836) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[11] <= 9.792545318603516) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9240506329113924, 0.0759493670886076}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 22.55500030517578) {
                            { double _tmp[] = {0.09090909090909091, 0.9090909090909091}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[4] <= 14.889999866485596) {
                if (input[2] <= 45.540000915527344) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[17] <= 13.654999732971191) {
                        if (input[2] <= 79.56999969482422) {
                            { double _tmp[] = {0.9935897435897436, 0.00641025641025641}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9230769230769231, 0.07692307692307693}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= -0.7865660786628723) {
                            { double _tmp[] = {0.9699248120300752, 0.03007518796992481}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[14] <= 0.7638603150844574) {
                    if (input[16] <= 3.2549999952316284) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.2, 0.8}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.25, 0.75}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 43.23500061035156) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 0.1599999964237213) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8125, 0.1875}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var13, var28, 2, var12);
    double var29[2];
    if (input[4] <= 8.305000305175781) {
        if (input[13] <= -0.00000000000000006123233601181349) {
            if (input[9] <= 19.99619960784912) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[11] <= 15.233301639556885) {
                    if (input[3] <= 173.86500549316406) {
                        if (input[10] <= 14.873586654663086) {
                            { double _tmp[] = {0.16666666666666666, 0.8333333333333334}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8873239436619719, 0.11267605633802817}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[16] <= 3.684999942779541) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[9] <= 24.957423210144043) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[7] <= 0.7049999833106995) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[0] <= 11.5) {
            if (input[4] <= 14.87999963760376) {
                if (input[2] <= 45.329999923706055) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[14] <= 0.8475330770015717) {
                        if (input[9] <= 19.939708709716797) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9482758620689655, 0.05172413793103448}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 13.173234939575195) {
                            { double _tmp[] = {0.9797979797979798, 0.020202020202020204}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.84375, 0.15625}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[3] <= 598.0350036621094) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[17] <= 17.699999809265137) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[11] <= 9.873369693756104) {
                            { double _tmp[] = {0.5714285714285714, 0.42857142857142855}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.896551724137931, 0.10344827586206896}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[8] <= 94.99821853637695) {
                if (input[15] <= 0.333456426858902) {
                    if (input[16] <= 3.84499990940094) {
                        if (input[8] <= 38.79018592834473) {
                            { double _tmp[] = {0.7924528301886793, 0.20754716981132076}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6354679802955665, 0.3645320197044335}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 43.40999984741211) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4142857142857143, 0.5857142857142857}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 19.996185302734375) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[10] <= 15.844984531402588) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2727272727272727, 0.7272727272727273}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var12, var29, 2, var11);
    double var30[2];
    if (input[18] <= 0.5) {
        if (input[2] <= 44.935001373291016) {
            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[8] <= 36.20341873168945) {
                if (input[20] <= 0.5) {
                    if (input[2] <= 80.29500198364258) {
                        if (input[5] <= 19.505000114440918) {
                            { double _tmp[] = {0.625, 0.375}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= -0.9367368817329407) {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 61.345001220703125) {
                        if (input[8] <= 7.326746225357056) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8518518518518519, 0.14814814814814814}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[4] <= 2.75) {
                    if (input[10] <= 13.192828178405762) {
                        if (input[7] <= 0.5249999761581421) {
                            { double _tmp[] = {0.7142857142857143, 0.2857142857142857}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[5] <= 25.270000457763672) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[16] <= 3.2450000047683716) {
                            { double _tmp[] = {0.9870967741935484, 0.012903225806451613}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9166666666666666, 0.08333333333333333}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[17] <= 15.429999828338623) {
            if (input[0] <= 13.5) {
                if (input[5] <= 45.744998931884766) {
                    if (input[15] <= 0.9999259114265442) {
                        if (input[2] <= 60.46000099182129) {
                            { double _tmp[] = {0.9423076923076923, 0.057692307692307696}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.988527724665392, 0.011472275334608031}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 9.143361568450928) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[15] <= -0.9158303439617157) {
                        if (input[3] <= 436.56500244140625) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.1, 0.9}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 21.57170009613037) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[10] <= 13.955301284790039) {
                    if (input[8] <= 26.365211486816406) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 19.74972915649414) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 0.9950000047683716) {
                        if (input[5] <= 37.77499961853027) {
                            { double _tmp[] = {0.7976190476190477, 0.20238095238095238}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5621181262729125, 0.4378818737270876}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[12] <= 0.12940952181816107) {
                if (input[7] <= 0.9050000011920929) {
                    if (input[21] <= 0.5) {
                        if (input[2] <= 60.80000114440918) {
                            { double _tmp[] = {0.2488479262672811, 0.7511520737327189}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7368421052631579, 0.2631578947368421}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 44.314998626708984) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5161290322580645, 0.4838709677419355}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 14.15165090560913) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[10] <= 19.58582878112793) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[2] <= 62.579999923706055) {
                    if (input[2] <= 52.64999961853027) {
                        if (input[3] <= 644.2449951171875) {
                            { double _tmp[] = {0.9302325581395349, 0.06976744186046512}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= -0.3252336382865906) {
                            { double _tmp[] = {0.9130434782608695, 0.08695652173913043}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9923664122137404, 0.007633587786259542}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 13.579601287841797) {
                        if (input[15] <= 0.012909817975014448) {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4, 0.6}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[4] <= 14.900000095367432) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var11, var30, 2, var10);
    double var31[2];
    if (input[18] <= 0.5) {
        if (input[1] <= 32.18499946594238) {
            if (input[12] <= -0.9829629063606262) {
                if (input[15] <= 0.9913467466831207) {
                    if (input[9] <= 20.115944862365723) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 0.6850000023841858) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9714285714285714, 0.02857142857142857}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 25.765000343322754) {
                        if (input[7] <= 0.26499998569488525) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[20] <= 0.5) {
                    if (input[9] <= 26.776142120361328) {
                        if (input[2] <= 68.77000045776367) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.16666666666666666, 0.8333333333333334}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 18.661924362182617) {
                            { double _tmp[] = {0.9880952380952381, 0.011904761904761904}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[17] <= 0.41499999165534973) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[13] <= 0.12940952181816104) {
                            { double _tmp[] = {0.9714285714285714, 0.02857142857142857}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9986842105263158, 0.0013157894736842105}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[5] <= 31.579999923706055) {
                { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[6] <= 29.469999313354492) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[5] <= 32.8700008392334) {
                        if (input[15] <= -0.4278756082057953) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[0] <= 11.5) {
            if (input[9] <= 20.176239013671875) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[6] <= 22.225000381469727) {
                    if (input[9] <= 22.516013145446777) {
                        if (input[15] <= -0.6518605798482895) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 20.605000495910645) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.2}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 95.1881217956543) {
                        if (input[17] <= 18.854999542236328) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[17] <= 13.815000057220459) {
                if (input[2] <= 44.09000015258789) {
                    if (input[5] <= 36.435001373291016) {
                        if (input[3] <= 300.13999938964844) {
                            { double _tmp[] = {0.3076923076923077, 0.6923076923076923}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[8] <= 95.00228118896484) {
                        if (input[9] <= 19.998287200927734) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.1072961373390558, 0.8927038626609443}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[11] <= 10.615569114685059) {
                    if (input[12] <= -0.12940952181816096) {
                        if (input[4] <= 14.505000114440918) {
                            { double _tmp[] = {0.1, 0.9}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3103448275862069, 0.6896551724137931}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.97438335418701) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 19.999879837036133) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 0.945000022649765) {
                            { double _tmp[] = {0.14606741573033707, 0.8539325842696629}; memcpy(var31, _tmp, 2 * sizeof(double)); }
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
        if (input[5] <= 33.28000068664551) {
            if (input[16] <= 2.5399999618530273) {
                if (input[15] <= 0.8121984899044037) {
                    if (input[8] <= 63.01349449157715) {
                        if (input[1] <= 22.97000026702881) {
                            { double _tmp[] = {0.125, 0.875}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[6] <= 15.039999961853027) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[8] <= 94.96965026855469) {
                    if (input[5] <= 26.4350004196167) {
                        if (input[13] <= 0.12940952181816104) {
                            { double _tmp[] = {0.6363636363636364, 0.36363636363636365}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9807692307692307, 0.019230769230769232}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 11.606968402862549) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[14] <= 0.5270728468894958) {
                if (input[6] <= 24.4350004196167) {
                    if (input[11] <= 11.241005897521973) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[21] <= 0.5) {
                    if (input[13] <= -0.9159756004810333) {
                        if (input[7] <= 1.070000022649765) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 57.98499870300293) {
                            { double _tmp[] = {0.4174757281553398, 0.5825242718446602}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.07692307692307693, 0.9230769230769231}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[8] <= 94.99332809448242) {
                        if (input[16] <= 4.184999942779541) {
                            { double _tmp[] = {0.17647058823529413, 0.8235294117647058}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
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
        if (input[9] <= 20.004332542419434) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[6] <= 21.55500030517578) {
                if (input[8] <= 83.384765625) {
                    if (input[18] <= 0.5) {
                        if (input[13] <= 0.12940952181816104) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8947368421052632, 0.10526315789473684}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[3] <= 156.36499786376953) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[7] <= 0.9399999976158142) {
                        if (input[2] <= 53.959999084472656) {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.95, 0.05}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[7] <= 1.0350000262260437) {
                    if (input[15] <= 0.6239285469055176) {
                        if (input[3] <= 551.1449890136719) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6, 0.4}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[15] <= 0.6963504254817963) {
            if (input[9] <= 20.001455307006836) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[8] <= 95.00228118896484) {
                    if (input[10] <= 20.448201179504395) {
                        if (input[16] <= 2.715000033378601) {
                            { double _tmp[] = {0.5238095238095238, 0.47619047619047616}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.27053140096618356, 0.7294685990338164}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 25.785053253173828) {
                            { double _tmp[] = {0.018957345971563982, 0.981042654028436}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[17] <= 8.539999961853027) {
                if (input[8] <= 49.91304016113281) {
                    if (input[14] <= 0.16280098259449005) {
                        if (input[5] <= 32.40500068664551) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[14] <= 0.6932555437088013) {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.7857142857142857, 0.21428571428571427}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[1] <= 27.394999504089355) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[10] <= 14.730948448181152) {
                    if (input[9] <= 19.91957378387451) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[16] <= 3.225000023841858) {
                        if (input[2] <= 45.57000160217285) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.675, 0.325}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 1.024999976158142) {
                            { double _tmp[] = {0.23076923076923078, 0.7692307692307693}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var8, var33, 2, var7);
    double var34[2];
    if (input[13] <= -0.379409521818161) {
        if (input[12] <= 0.12940952181816107) {
            if (input[3] <= 418.7099914550781) {
                if (input[2] <= 63.07000160217285) {
                    if (input[0] <= 13.5) {
                        if (input[16] <= 2.690000057220459) {
                            { double _tmp[] = {0.9, 0.1}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 19.982534408569336) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2537313432835821, 0.746268656716418}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[3] <= 300.625) {
                        if (input[15] <= -0.8140159547328949) {
                            { double _tmp[] = {0.47058823529411764, 0.5294117647058824}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 39.443084716796875) {
                            { double _tmp[] = {0.963302752293578, 0.03669724770642202}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 19.999879837036133) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[5] <= 41.85000038146973) {
                            { double _tmp[] = {0.25, 0.75}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9714285714285714, 0.02857142857142857}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.9699999988079071) {
                            { double _tmp[] = {0.010309278350515464, 0.9896907216494846}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[4] <= 14.889999866485596) {
                if (input[20] <= 0.5) {
                    if (input[15] <= -0.8429103195667267) {
                        if (input[8] <= 95.14529800415039) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.28999999165534973) {
                            { double _tmp[] = {0.9, 0.1}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[4] <= 12.545000076293945) {
                        if (input[1] <= 29.369999885559082) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9903846153846154, 0.009615384615384616}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 8.996389389038086) {
                            { double _tmp[] = {0.7142857142857143, 0.2857142857142857}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9820143884892086, 0.017985611510791366}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[5] <= 44.59000015258789) {
                    if (input[11] <= 11.154134750366211) {
                        if (input[9] <= 19.945741653442383) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.0800000429153442) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.09090909090909091, 0.9090909090909091}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[4] <= 15.804999828338623) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[11] <= 12.294300079345703) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[2] <= 44.44000053405762) {
            if (input[15] <= 0.972217321395874) {
                if (input[11] <= 9.597328186035156) {
                    if (input[1] <= 26.800000190734863) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[2] <= 58.885000228881836) {
                if (input[17] <= 3.3200000524520874) {
                    if (input[15] <= 0.9999259114265442) {
                        if (input[17] <= 0.1550000011920929) {
                            { double _tmp[] = {0.9931972789115646, 0.006802721088435374}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9263157894736842, 0.07368421052631578}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 26.436800003051758) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 20.561457633972168) {
                        if (input[9] <= 19.928730964660645) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.64, 0.36}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= -0.8930909335613251) {
                            { double _tmp[] = {0.7692307692307693, 0.23076923076923078}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3, 0.7}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 20.004352569580078) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[7] <= 1.020000010728836) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var7, var34, 2, var6);
    double var35[2];
    if (input[17] <= 5.664999961853027) {
        if (input[1] <= 32.60499954223633) {
            if (input[2] <= 44.39500045776367) {
                if (input[14] <= 0.23009244352579117) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[4] <= 7.979999780654907) {
                        if (input[16] <= 2.4649999141693115) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[5] <= 31.229999542236328) {
                    if (input[2] <= 44.77499961853027) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 20.133987426757812) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9523809523809523, 0.047619047619047616}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[14] <= -0.017212719190865755) {
                        if (input[9] <= 19.983853340148926) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[15] <= -0.9993703663349152) {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9202453987730062, 0.07975460122699386}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[9] <= 20.028748512268066) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
            }
        }
    } else {
        if (input[9] <= 20.00075054168701) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[7] <= 0.9750000238418579) {
                if (input[9] <= 28.082053184509277) {
                    if (input[21] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 0.8199999928474426) {
                            { double _tmp[] = {0.013157894736842105, 0.9868421052631579}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6, 0.4}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 63.7400016784668) {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9047619047619048, 0.09523809523809523}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[14] <= 0.4894797056913376) {
                    if (input[9] <= 22.14533519744873) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    }
    add_vectors(var6, var35, 2, var5);
    double var36[2];
    if (input[1] <= 26.515000343322754) {
        if (input[3] <= 595.1099853515625) {
            if (input[5] <= 25.195000648498535) {
                if (input[15] <= 0.9999259114265442) {
                    if (input[14] <= 0.999657392501831) {
                        if (input[7] <= 0.6550000011920929) {
                            { double _tmp[] = {0.9916666666666667, 0.008333333333333333}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.8181818181818182, 0.18181818181818182}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[6] <= 15.039999961853027) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[5] <= 17.979999542236328) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[9] <= 20.009490966796875) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[11] <= 18.522881507873535) {
                            { double _tmp[] = {0.9230769230769231, 0.07692307692307693}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[11] <= 10.038733959197998) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6111111111111112, 0.3888888888888889}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[14] <= 0.14579379558563232) {
                if (input[8] <= 29.6202392578125) {
                    if (input[2] <= 47.209999084472656) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[13] <= -0.9829629063606262) {
                    if (input[16] <= 4.085000038146973) {
                        if (input[2] <= 43.08500099182129) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.09090909090909091, 0.9090909090909091}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[17] <= 19.024999618530273) {
                        if (input[15] <= -0.12443776801228523) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.7307692307692307, 0.2692307692307692}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[17] <= 13.694999694824219) {
            if (input[4] <= 7.075000047683716) {
                if (input[6] <= 23.585000038146973) {
                    if (input[0] <= 18.5) {
                        if (input[7] <= 0.6749999821186066) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[11] <= 10.070722579956055) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[5] <= 36.329999923706055) {
                            { double _tmp[] = {0.9921752738654147, 0.00782472613458529}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[15] <= 0.9051596522331238) {
                    if (input[9] <= 20.001455307006836) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 23.100197792053223) {
                            { double _tmp[] = {0.13147410358565736, 0.8685258964143426}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.92, 0.08}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 10.068953514099121) {
                        if (input[2] <= 41.380001068115234) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4, 0.6}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 41.474998474121094) {
                            { double _tmp[] = {0.7272727272727273, 0.2727272727272727}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[14] <= 0.42109696567058563) {
                if (input[0] <= 12.5) {
                    if (input[2] <= 54.625) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[9] <= 20.61152935028076) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.015706062316895) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[9] <= 20.206366539001465) {
                    if (input[6] <= 23.61500072479248) {
                        if (input[8] <= 44.0090389251709) {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[20] <= 0.5) {
                        if (input[6] <= 26.119999885559082) {
                            { double _tmp[] = {0.9393939393939394, 0.06060606060606061}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 21.643238067626953) {
                            { double _tmp[] = {0.3522727272727273, 0.6477272727272727}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.15172413793103448, 0.8482758620689655}; memcpy(var36, _tmp, 2 * sizeof(double)); }
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
        if (input[9] <= 27.11260986328125) {
            if (input[3] <= 49.21500015258789) {
                if (input[13] <= -0.00000000000000006123233601181349) {
                    if (input[15] <= 0.43407389521598816) {
                        if (input[8] <= 47.32229042053223) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[11] <= 9.155507564544678) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 1.405000001192093) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[1] <= 30.5649995803833) {
                    if (input[7] <= 1.0) {
                        if (input[7] <= 0.5249999761581421) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.030927835051546393, 0.9690721649484536}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[8] <= 94.99740600585938) {
                if (input[5] <= 26.6850004196167) {
                    if (input[14] <= 0.9985467195510864) {
                        if (input[9] <= 92.50265884399414) {
                            { double _tmp[] = {0.9402985074626866, 0.05970149253731343}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[0] <= 3.5) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.2, 0.8}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[17] <= 18.579999923706055) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[4] <= 14.845000267028809) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var4, var37, 2, var3);
    double var38[2];
    if (input[2] <= 61.17499923706055) {
        if (input[7] <= 0.9950000047683716) {
            if (input[2] <= 46.05999946594238) {
                if (input[6] <= 22.4399995803833) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[14] <= 0.6728453934192657) {
                        if (input[1] <= 28.84999942779541) {
                            { double _tmp[] = {0.2222222222222222, 0.7777777777777778}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[13] <= -0.379409521818161) {
                    if (input[1] <= 26.704999923706055) {
                        if (input[5] <= 42.90999984741211) {
                            { double _tmp[] = {0.9594594594594594, 0.04054054054054054}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.819047619047619, 0.18095238095238095}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 45.73500061035156) {
                            { double _tmp[] = {0.660377358490566, 0.33962264150943394}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.32978723404255317, 0.6702127659574468}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[4] <= 7.180000066757202) {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9739583333333334, 0.026041666666666668}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[10] <= 22.841615676879883) {
                            { double _tmp[] = {0.8760330578512396, 0.12396694214876033}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3, 0.7}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
        }
    } else {
        if (input[1] <= 32.545000076293945) {
            if (input[13] <= -0.9159756004810333) {
                if (input[14] <= 0.7236172556877136) {
                    if (input[11] <= 14.200016975402832) {
                        if (input[2] <= 63.60500144958496) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.26206398010254) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[11] <= 15.514918804168701) {
                        if (input[17] <= 15.424999713897705) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9230769230769231, 0.07692307692307693}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.759999990463257) {
                            { double _tmp[] = {0.09090909090909091, 0.9090909090909091}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[14] <= 0.999657392501831) {
                    if (input[20] <= 0.5) {
                        if (input[7] <= 0.9600000083446503) {
                            { double _tmp[] = {0.45, 0.55}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[16] <= 3.8399999141693115) {
                            { double _tmp[] = {0.9971006088721368, 0.0028993911278631487}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[12] <= 0.9829629063606262) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[8] <= 26.995787620544434) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[14] <= -0.920937180519104) {
                if (input[17] <= 10.714999675750732) {
                    if (input[9] <= 19.58745765686035) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[9] <= 20.1402645111084) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    }
    add_vectors(var3, var38, 2, var2);
    double var39[2];
    if (input[2] <= 61.39000129699707) {
        if (input[5] <= 35.404998779296875) {
            if (input[2] <= 44.44000053405762) {
                if (input[2] <= 43.48500061035156) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[2] <= 43.72999954223633) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[1] <= 27.90499973297119) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[10] <= 23.350232124328613) {
                    if (input[5] <= 33.19000053405762) {
                        if (input[4] <= 2.75) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9571428571428572, 0.04285714285714286}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[8] <= 72.94145202636719) {
                            { double _tmp[] = {0.9322033898305084, 0.06779661016949153}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 23.829968452453613) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[21] <= 0.5) {
                if (input[0] <= 11.5) {
                    if (input[4] <= 14.869999885559082) {
                        if (input[8] <= 20.30667209625244) {
                            { double _tmp[] = {0.8, 0.2}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9912280701754386, 0.008771929824561403}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[17] <= 18.645000457763672) {
                            { double _tmp[] = {0.3, 0.7}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8148148148148148, 0.18518518518518517}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 16.084827423095703) {
                        if (input[2] <= 40.44000053405762) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.37404580152671757, 0.6259541984732825}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 44.69499969482422) {
                            { double _tmp[] = {0.6855524079320113, 0.31444759206798867}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.4604651162790698, 0.5395348837209303}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[8] <= 95.0129508972168) {
                    if (input[10] <= 20.33884334564209) {
                        if (input[2] <= 49.170000076293945) {
                            { double _tmp[] = {0.25, 0.75}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.72, 0.28}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 26.69499969482422) {
                            { double _tmp[] = {0.08333333333333333, 0.9166666666666666}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5294117647058824, 0.47058823529411764}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[11] <= 20.35335063934326) {
            if (input[3] <= 498.12001037597656) {
                if (input[4] <= 11.125) {
                    if (input[9] <= 20.004352569580078) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[8] <= 90.27046585083008) {
                            { double _tmp[] = {0.803030303030303, 0.19696969696969696}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 62.540000915527344) {
                        if (input[0] <= 13.5) {
                            { double _tmp[] = {0.975, 0.025}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.1, 0.9}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[9] <= 20.563803672790527) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[1] <= 28.77500057220459) {
                    if (input[14] <= 0.999657392501831) {
                        if (input[11] <= 14.162344932556152) {
                            { double _tmp[] = {0.8837209302325582, 0.11627906976744186}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[7] <= 0.42500001192092896) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 20.181438446044922) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[10] <= 25.24909210205078) {
                if (input[3] <= 48.78499984741211) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[8] <= 24.827689170837402) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[9] <= 20.14243221282959) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    }
    add_vectors(var2, var39, 2, var1);
    mul_vector_number(var1, 0.05, 2, var0);
    memcpy(output, var0, 2 * sizeof(double));
}
