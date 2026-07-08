#pragma once

#include "control/generated/model_utils.h"

#include <string.h>


inline void predict_heater_on_label(const double * input, double * output) {
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
    if (input[5] <= 16.824999809265137) {
        if (input[1] <= 17.4350004196167) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[12] <= 0.7865660786628723) {
                { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
            }
        }
    } else {
        if (input[8] <= 94.87106323242188) {
            if (input[20] <= 0.5) {
                if (input[10] <= 15.638344764709473) {
                    if (input[14] <= 0.8306780755519867) {
                        if (input[2] <= 72.58000183105469) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[2] <= 46.36000061035156) {
                if (input[16] <= 4.299999952316284) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[8] <= 94.9261360168457) {
                    if (input[3] <= 204.0399932861328) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[14] <= 0.793795257806778) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[2] <= 52.40500068664551) {
                        if (input[2] <= 52.27499961853027) {
                            { double _tmp[] = {0.9878048780487805, 0.012195121951219513}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var20, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    double var21[2];
    if (input[15] <= 0.9999259114265442) {
        if (input[16] <= 4.299999952316284) {
            if (input[3] <= 423.2799987792969) {
                if (input[9] <= 35.31500816345215) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[17] <= -0.8600000143051147) {
                        if (input[6] <= 19.744999885559082) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8, 0.2}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[6] <= 15.375) {
                            { double _tmp[] = {0.9857142857142858, 0.014285714285714285}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[20] <= 0.5) {
                    if (input[8] <= 94.99821853637695) {
                        if (input[1] <= 24.625) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9, 0.1}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[2] <= 46.36000061035156) {
                { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[5] <= 33.21500015258789) {
                    if (input[5] <= 32.75) {
                        if (input[1] <= 26.84500026702881) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[6] <= 13.480000019073486) {
            if (input[1] <= 16.644999504089355) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var21, _tmp, 2 * sizeof(double)); }
        }
    }
    add_vectors(var20, var21, 2, var19);
    double var22[2];
    if (input[20] <= 0.5) {
        if (input[8] <= 94.99528884887695) {
            if (input[14] <= 0.9670369923114777) {
                if (input[17] <= -0.8199999928474426) {
                    if (input[12] <= 0.7329629063606262) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[1] <= 21.824999809265137) {
                        if (input[4] <= 10.110000133514404) {
                            { double _tmp[] = {0.95, 0.05}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[9] <= 48.85969352722168) {
                    if (input[8] <= 94.9316177368164) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[2] <= 52.47500038146973) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
        }
    } else {
        { double _tmp[] = {1.0, 0.0}; memcpy(var22, _tmp, 2 * sizeof(double)); }
    }
    add_vectors(var19, var22, 2, var18);
    double var23[2];
    if (input[4] <= 6.194999933242798) {
        if (input[0] <= 18.5) {
            if (input[7] <= 0.6550000011920929) {
                if (input[9] <= 34.242788314819336) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
        }
    } else {
        { double _tmp[] = {1.0, 0.0}; memcpy(var23, _tmp, 2 * sizeof(double)); }
    }
    add_vectors(var18, var23, 2, var17);
    double var24[2];
    if (input[1] <= 18.52500057220459) {
        if (input[8] <= 23.305874824523926) {
            if (input[11] <= 9.993959426879883) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[6] <= 14.015000343322754) {
                if (input[11] <= 9.155281066894531) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[14] <= 0.6390428841114044) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
            }
        }
    } else {
        if (input[10] <= 16.247224807739258) {
            if (input[15] <= 0.6453242003917694) {
                if (input[7] <= 0.9750000238418579) {
                    if (input[10] <= 16.232136726379395) {
                        if (input[14] <= 0.9978801906108856) {
                            { double _tmp[] = {0.9859154929577465, 0.014084507042253521}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.6, 0.4}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var24, _tmp, 2 * sizeof(double)); }
        }
    }
    add_vectors(var17, var24, 2, var16);
    double var25[2];
    if (input[8] <= 94.88442611694336) {
        if (input[5] <= 16.824999809265137) {
            if (input[5] <= 16.800000190734863) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[13] <= 0.6035533845424652) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[9] <= 44.48095703125) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[12] <= 0.7865660786628723) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[16] <= 3.259999990463257) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[2] <= 46.36000061035156) {
            if (input[2] <= 46.30000114440918) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[11] <= 11.309805870056152) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[6] <= 20.539999961853027) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[6] <= 20.5649995803833) {
                    if (input[20] <= 0.5) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[17] <= -0.7749999761581421) {
                        if (input[12] <= -0.9829629063606262) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[0] <= 17.5) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.967741935483871, 0.03225806451612903}; memcpy(var25, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var16, var25, 2, var15);
    double var26[2];
    if (input[16] <= 3.7649999856948853) {
        if (input[6] <= 20.755000114440918) {
            if (input[6] <= 20.739999771118164) {
                if (input[14] <= 0.999657392501831) {
                    if (input[12] <= 0.9829629063606262) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[6] <= 18.089999198913574) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9803921568627451, 0.0196078431372549}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[5] <= 18.594999313354492) {
                        if (input[14] <= 0.9998796284198761) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[2] <= 79.13000106811523) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
        }
    } else {
        if (input[12] <= -0.9829629063606262) {
            if (input[15] <= 0.5912395417690277) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[7] <= 0.679999977350235) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[4] <= 12.199999809265137) {
                if (input[8] <= 94.99528884887695) {
                    if (input[20] <= 0.5) {
                        if (input[0] <= 8.0) {
                            { double _tmp[] = {0.8636363636363636, 0.13636363636363635}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.14285714285714285, 0.8571428571428571}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var26, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var15, var26, 2, var14);
    double var27[2];
    if (input[2] <= 53.66499900817871) {
        if (input[12] <= -0.9829629063606262) {
            if (input[5] <= 25.270000457763672) {
                if (input[16] <= 3.8550000190734863) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[6] <= 22.230000495910645) {
                    if (input[10] <= 16.303824424743652) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[9] <= 46.06806564331055) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[9] <= 47.96743392944336) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[6] <= 14.019999980926514) {
            if (input[5] <= 16.8149995803833) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[15] <= 0.7498552203178406) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[12] <= 0.6035533845424652) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[11] <= 11.71471357345581) {
                if (input[9] <= 39.61874198913574) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[17] <= -0.9549999833106995) {
                        if (input[15] <= 0.5415475964546204) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[14] <= 0.845217764377594) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9117647058823529, 0.08823529411764706}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[6] <= 20.755000114440918) {
                    if (input[9] <= 34.89191246032715) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[15] <= -0.9367368817329407) {
                            { double _tmp[] = {0.6666666666666666, 0.3333333333333333}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var27, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    }
    add_vectors(var14, var27, 2, var13);
    double var28[2];
    if (input[10] <= 16.647302627563477) {
        if (input[17] <= -0.29500000178813934) {
            if (input[9] <= 91.94257354736328) {
                if (input[9] <= 39.426822662353516) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[15] <= 0.7629082202911377) {
                        if (input[7] <= 0.6599999815225601) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[13] <= 0.7865660786628723) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[5] <= 24.655000686645508) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[5] <= 25.905000686645508) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[15] <= 0.9999259114265442) {
                if (input[1] <= 29.265000343322754) {
                    if (input[20] <= 0.5) {
                        if (input[21] <= 0.5) {
                            { double _tmp[] = {0.9090909090909091, 0.09090909090909091}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9957081545064378, 0.004291845493562232}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[2] <= 46.22500038146973) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[8] <= 17.877384185791016) {
                    if (input[11] <= 8.739941120147705) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[1] <= 22.925000190734863) {
            if (input[10] <= 20.697734832763672) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[15] <= -0.9883025586605072) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var28, _tmp, 2 * sizeof(double)); }
        }
    }
    add_vectors(var13, var28, 2, var12);
    double var29[2];
    if (input[14] <= 0.9937373995780945) {
        if (input[17] <= -0.8650000095367432) {
            if (input[12] <= 0.9159756004810333) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[1] <= 20.579999923706055) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[1] <= 20.800000190734863) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[20] <= 0.5) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        } else {
            if (input[9] <= 63.10833168029785) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[21] <= 0.5) {
                    if (input[7] <= 1.520000010728836) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[17] <= -0.7599999904632568) {
                        if (input[2] <= 59.33000183105469) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[5] <= 27.050000190734863) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9859154929577465, 0.014084507042253521}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[7] <= 0.9050000011920929) {
            if (input[3] <= 491.15501403808594) {
                if (input[9] <= 31.5991153717041) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[2] <= 51.30500030517578) {
                        if (input[8] <= 95.48003387451172) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var29, _tmp, 2 * sizeof(double)); }
        }
    }
    add_vectors(var12, var29, 2, var11);
    double var30[2];
    if (input[15] <= 0.9999259114265442) {
        if (input[6] <= 15.244999885559082) {
            if (input[7] <= 0.9600000083446503) {
                { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[17] <= -0.9549999833106995) {
                if (input[9] <= 39.426822662353516) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[5] <= 21.234999656677246) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[7] <= 0.5849999785423279) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[2] <= 60.46000099182129) {
                        if (input[8] <= 94.8587646484375) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9769230769230769, 0.023076923076923078}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        if (input[2] <= 87.34499740600586) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.9965156794425087, 0.003484320557491289}; memcpy(var30, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            }
        }
    } else {
        if (input[6] <= 13.369999885559082) {
            { double _tmp[] = {0.0, 1.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var30, _tmp, 2 * sizeof(double)); }
        }
    }
    add_vectors(var11, var30, 2, var10);
    double var31[2];
    if (input[21] <= 0.5) {
        if (input[0] <= 6.5) {
            if (input[16] <= 3.7300000190734863) {
                if (input[15] <= -0.9993703663349152) {
                    if (input[9] <= 30.272245407104492) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 2.455000102519989) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[9] <= 39.53250312805176) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[7] <= 0.7299999743700027) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                if (input[12] <= 0.6035533845424652) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[11] <= 11.034914493560791) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
        }
    } else {
        if (input[9] <= 45.59709167480469) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[9] <= 45.743709564208984) {
                { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[7] <= 0.6500000059604645) {
                    if (input[0] <= 17.5) {
                        if (input[14] <= 0.9135448038578033) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8571428571428571, 0.14285714285714285}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var31, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    }
    add_vectors(var10, var31, 2, var9);
    double var32[2];
    if (input[9] <= 86.82854843139648) {
        if (input[5] <= 22.054999351501465) {
            if (input[1] <= 22.90499973297119) {
                if (input[20] <= 0.5) {
                    if (input[8] <= 48.73029136657715) {
                        if (input[6] <= 17.934999465942383) {
                            { double _tmp[] = {0.9705882352941176, 0.029411764705882353}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
        }
    } else {
        if (input[1] <= 21.255000114440918) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[4] <= 11.960000038146973) {
                if (input[15] <= 0.6050336360931396) {
                    if (input[12] <= 0.10355338454246521) {
                        if (input[12] <= -0.9829629063606262) {
                            { double _tmp[] = {0.8333333333333334, 0.16666666666666666}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var32, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var9, var32, 2, var8);
    double var33[2];
    if (input[8] <= 94.88442611694336) {
        if (input[9] <= 34.37959289550781) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[12] <= 0.9829629063606262) {
                if (input[8] <= 29.054317474365234) {
                    if (input[6] <= 13.480000019073486) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[15] <= -0.928108811378479) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[6] <= 15.389999866485596) {
                            { double _tmp[] = {0.3333333333333333, 0.6666666666666666}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
            }
        }
    } else {
        if (input[7] <= 0.6449999809265137) {
            if (input[12] <= -0.9829629063606262) {
                if (input[7] <= 0.5949999988079071) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[7] <= 0.6349999904632568) {
                    if (input[1] <= 29.295000076293945) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[10] <= 16.63202476501465) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            if (input[14] <= 0.9978801906108856) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[4] <= 12.924999713897705) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[13] <= -0.7865660786628723) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var33, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var8, var33, 2, var7);
    double var34[2];
    if (input[17] <= -0.625) {
        if (input[12] <= 0.6035533845424652) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[16] <= 3.3700000047683716) {
                if (input[15] <= -0.9993703663349152) {
                    if (input[17] <= -0.875) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[16] <= 3.7350001335144043) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[9] <= 47.63337326049805) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[13] <= 0.7865660786628723) {
                if (input[21] <= 0.5) {
                    if (input[7] <= 0.8449999988079071) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[9] <= 47.74746513366699) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[12] <= -0.9829629063606262) {
                            { double _tmp[] = {0.9, 0.1}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var34, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var7, var34, 2, var6);
    double var35[2];
    if (input[20] <= 0.5) {
        if (input[15] <= -0.9367368817329407) {
            if (input[8] <= 28.471036911010742) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[13] <= -0.00000000000000006123233601181349) {
                if (input[5] <= 26.070000648498535) {
                    if (input[17] <= -0.08500000834465027) {
                        if (input[5] <= 25.320000648498535) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.8333333333333334, 0.16666666666666666}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[14] <= 0.8358945250511169) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[8] <= 95.00122451782227) {
                            { double _tmp[] = {0.5, 0.5}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
                        }
                    }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
            }
        }
    } else {
        { double _tmp[] = {1.0, 0.0}; memcpy(var35, _tmp, 2 * sizeof(double)); }
    }
    add_vectors(var6, var35, 2, var5);
    double var36[2];
    if (input[15] <= 0.012909817975014448) {
        if (input[6] <= 20.755000114440918) {
            if (input[8] <= 29.76422119140625) {
                if (input[15] <= -0.9989260733127594) {
                    if (input[10] <= 20.573373794555664) {
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
            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
        }
    } else {
        if (input[16] <= 4.0350000858306885) {
            if (input[8] <= 20.713461875915527) {
                if (input[17] <= 0.014999998733401299) {
                    if (input[8] <= 19.739837646484375) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[17] <= -0.9549999833106995) {
                    if (input[9] <= 39.426822662353516) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        if (input[6] <= 19.53499984741211) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    }
                } else {
                    if (input[10] <= 12.735166549682617) {
                        if (input[10] <= 12.730486392974854) {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[12] <= -0.9829629063606262) {
                if (input[17] <= -0.4699999988079071) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[1] <= 27.199999809265137) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[10] <= 17.75522232055664) {
                    if (input[8] <= 94.97751235961914) {
                        if (input[14] <= 0.9920752048492432) {
                            { double _tmp[] = {0.98, 0.02}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.75, 0.25}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    if (input[13] <= -0.7865660786628723) {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var36, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    }
    add_vectors(var5, var36, 2, var4);
    double var37[2];
    if (input[9] <= 90.97573471069336) {
        if (input[9] <= 35.18412971496582) {
            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
        } else {
            if (input[12] <= 0.6035533845424652) {
                if (input[4] <= 2.75) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[3] <= 431.4649963378906) {
                        if (input[8] <= 95.00971603393555) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[2] <= 58.11000061035156) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[7] <= 1.0699999928474426) {
                        if (input[2] <= 68.57500076293945) {
                            { double _tmp[] = {0.8888888888888888, 0.1111111111111111}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        }
    } else {
        if (input[8] <= 95.00100326538086) {
            if (input[10] <= 16.076271533966064) {
                if (input[7] <= 0.9749999940395355) {
                    if (input[6] <= 21.59000015258789) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var37, _tmp, 2 * sizeof(double)); }
        }
    }
    add_vectors(var4, var37, 2, var3);
    double var38[2];
    if (input[20] <= 0.5) {
        if (input[8] <= 94.99740600585938) {
            if (input[9] <= 34.242788314819336) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
            } else {
                if (input[13] <= 0.7865660786628723) {
                    if (input[7] <= 1.1650000214576721) {
                        if (input[17] <= 15.704999446868896) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
                }
            }
        } else {
            { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
        }
    } else {
        { double _tmp[] = {1.0, 0.0}; memcpy(var38, _tmp, 2 * sizeof(double)); }
    }
    add_vectors(var3, var38, 2, var2);
    double var39[2];
    if (input[16] <= 4.2200000286102295) {
        if (input[14] <= 0.9955121576786041) {
            if (input[9] <= 63.10833168029785) {
                if (input[17] <= -0.9549999833106995) {
                    if (input[20] <= 0.5) {
                        if (input[1] <= 22.199999809265137) {
                            { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        } else {
                            { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                        }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                }
            } else {
                if (input[11] <= 11.01078987121582) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[11] <= 11.104202270507812) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                }
            }
        } else {
            if (input[16] <= 4.0) {
                if (input[9] <= 39.22304725646973) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                } else {
                    if (input[9] <= 40.0692138671875) {
                        { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    } else {
                        { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                    }
                }
            } else {
                if (input[14] <= 0.9966219663619995) {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                }
            }
        }
    } else {
        if (input[16] <= 4.234999895095825) {
            if (input[4] <= 2.75) {
                { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
            } else {
                { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
            }
        } else {
            if (input[2] <= 46.36000061035156) {
                if (input[6] <= 24.550000190734863) {
                    { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                } else {
                    { double _tmp[] = {0.0, 1.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
                }
            } else {
                { double _tmp[] = {1.0, 0.0}; memcpy(var39, _tmp, 2 * sizeof(double)); }
            }
        }
    }
    add_vectors(var2, var39, 2, var1);
    mul_vector_number(var1, 0.05, 2, var0);
    memcpy(output, var0, 2 * sizeof(double));
}
