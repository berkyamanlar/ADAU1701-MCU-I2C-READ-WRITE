/*
 * File:           C:\Users\MSI\Desktop\BERK\SS Project Files\Original\Exports\DSP_2024_05_13_IC_1_PARAM.h
 *
 * Created:        Wednesday, November 13, 2024 9:27:55 AM
 * Description:    DSP_2024_05_13:IC 1 parameter RAM definitions.
 *
 * This software is distributed in the hope that it will be useful,
 * but is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * This software may only be used to program products purchased from
 * Analog Devices for incorporation by you into audio products that
 * are intended for resale to audio product end users. This software
 * may not be distributed whole or in any part to third parties.
 *
 * Copyright ©2024 Analog Devices, Inc. All rights reserved.
 */
#ifndef __DSP_2024_05_13_IC_1_PARAM_H__
#define __DSP_2024_05_13_IC_1_PARAM_H__


/* Module Switch1 - On/Off Switch*/
#define MOD_SWITCH1_COUNT                              1
#define MOD_SWITCH1_DEVICE                             "IC1"
#define MOD_SWITCH1_ISON_ADDR                          0
#define MOD_SWITCH1_ISON_FIXPT                         0x00000000
#define MOD_SWITCH1_ISON_VALUE                         SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0)
#define MOD_SWITCH1_ISON_TYPE                          SIGMASTUDIOTYPE_FIXPOINT

/* Module DC1 - DC Input Entry*/
#define MOD_DC1_COUNT                                  1
#define MOD_DC1_DEVICE                                 "IC1"
#define MOD_DC1_DCINPALG3_ADDR                         1
#define MOD_DC1_DCINPALG3_FIXPT                        0x00000000
#define MOD_DC1_DCINPALG3_VALUE                        SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0)
#define MOD_DC1_DCINPALG3_TYPE                         SIGMASTUDIOTYPE_FIXPOINT

/* Module Tone1 - Sine Tone*/
#define MOD_TONE1_COUNT                                3
#define MOD_TONE1_DEVICE                               "IC1"
#define MOD_STATIC_TONE1_ALG0_MASK_ADDR                2
#define MOD_STATIC_TONE1_ALG0_MASK_FIXPT               0x000000FF
#define MOD_STATIC_TONE1_ALG0_MASK_VALUE               SIGMASTUDIOTYPE_INTEGER_CONVERT(255)
#define MOD_STATIC_TONE1_ALG0_MASK_TYPE                SIGMASTUDIOTYPE_INTEGER
#define MOD_TONE1_ALG0_INCREMENT_ADDR                  3
#define MOD_TONE1_ALG0_INCREMENT_FIXPT                 0x002AAAAA
#define MOD_TONE1_ALG0_INCREMENT_VALUE                 SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0.333333333333333)
#define MOD_TONE1_ALG0_INCREMENT_TYPE                  SIGMASTUDIOTYPE_FIXPOINT
#define MOD_TONE1_ALG0_ON_ADDR                         4
#define MOD_TONE1_ALG0_ON_FIXPT                        0x00800000
#define MOD_TONE1_ALG0_ON_VALUE                        SIGMASTUDIOTYPE_FIXPOINT_CONVERT(1)
#define MOD_TONE1_ALG0_ON_TYPE                         SIGMASTUDIOTYPE_FIXPOINT

/* Module Switch1_2 - On/Off Switch*/
#define MOD_SWITCH1_2_COUNT                            1
#define MOD_SWITCH1_2_DEVICE                           "IC1"
#define MOD_SWITCH1_2_ISON_ADDR                        5
#define MOD_SWITCH1_2_ISON_FIXPT                       0x00000000
#define MOD_SWITCH1_2_ISON_VALUE                       SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0)
#define MOD_SWITCH1_2_ISON_TYPE                        SIGMASTUDIOTYPE_FIXPOINT

/* Module Switch1_3 - On/Off Switch*/
#define MOD_SWITCH1_3_COUNT                            1
#define MOD_SWITCH1_3_DEVICE                           "IC1"
#define MOD_SWITCH1_3_ISON_ADDR                        6
#define MOD_SWITCH1_3_ISON_FIXPT                       0x00000000
#define MOD_SWITCH1_3_ISON_VALUE                       SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0)
#define MOD_SWITCH1_3_ISON_TYPE                        SIGMASTUDIOTYPE_FIXPOINT

/* Module Gain3 - Gain*/
#define MOD_GAIN3_COUNT                                1
#define MOD_GAIN3_DEVICE                               "IC1"
#define MOD_GAIN3_GAIN1940ALGNS1_ADDR                  7
#define MOD_GAIN3_GAIN1940ALGNS1_FIXPT                 0x00333333
#define MOD_GAIN3_GAIN1940ALGNS1_VALUE                 SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0.4)
#define MOD_GAIN3_GAIN1940ALGNS1_TYPE                  SIGMASTUDIOTYPE_FIXPOINT

/* Module Gain1 - Gain*/
#define MOD_GAIN1_COUNT                                1
#define MOD_GAIN1_DEVICE                               "IC1"
#define MOD_GAIN1_GAIN1940ALGNS3_ADDR                  8
#define MOD_GAIN1_GAIN1940ALGNS3_FIXPT                 0x02000000
#define MOD_GAIN1_GAIN1940ALGNS3_VALUE                 SIGMASTUDIOTYPE_FIXPOINT_CONVERT(4)
#define MOD_GAIN1_GAIN1940ALGNS3_TYPE                  SIGMASTUDIOTYPE_FIXPOINT

/* Module Gen Filter1 - General (2nd order)*/
#define MOD_GENFILTER1_COUNT                           5
#define MOD_GENFILTER1_DEVICE                          "IC1"
#define MOD_GENFILTER1_ALG0_STAGE0_B0_ADDR             9
#define MOD_GENFILTER1_ALG0_STAGE0_B0_FIXPT            0x007FC3DE
#define MOD_GENFILTER1_ALG0_STAGE0_B0_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0.99816489289114)
#define MOD_GENFILTER1_ALG0_STAGE0_B0_TYPE             SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GENFILTER1_ALG0_STAGE0_B1_ADDR             10
#define MOD_GENFILTER1_ALG0_STAGE0_B1_FIXPT            0xFF0079AB
#define MOD_GENFILTER1_ALG0_STAGE0_B1_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(-1.99628702772042)
#define MOD_GENFILTER1_ALG0_STAGE0_B1_TYPE             SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GENFILTER1_ALG0_STAGE0_B2_ADDR             11
#define MOD_GENFILTER1_ALG0_STAGE0_B2_FIXPT            0x007FC3DE
#define MOD_GENFILTER1_ALG0_STAGE0_B2_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0.99816489289114)
#define MOD_GENFILTER1_ALG0_STAGE0_B2_TYPE             SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GENFILTER1_ALG0_STAGE0_A0_ADDR             12
#define MOD_GENFILTER1_ALG0_STAGE0_A0_FIXPT            0x00FF8655
#define MOD_GENFILTER1_ALG0_STAGE0_A0_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(1.99628702772042)
#define MOD_GENFILTER1_ALG0_STAGE0_A0_TYPE             SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GENFILTER1_ALG0_STAGE0_A1_ADDR             13
#define MOD_GENFILTER1_ALG0_STAGE0_A1_FIXPT            0xFF807844
#define MOD_GENFILTER1_ALG0_STAGE0_A1_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(-0.99632978578228)
#define MOD_GENFILTER1_ALG0_STAGE0_A1_TYPE             SIGMASTUDIOTYPE_FIXPOINT

/* Module Gen Filter2 - General (2nd order)*/
#define MOD_GENFILTER2_COUNT                           5
#define MOD_GENFILTER2_DEVICE                          "IC1"
#define MOD_GENFILTER2_ALG0_STAGE0_B0_ADDR             14
#define MOD_GENFILTER2_ALG0_STAGE0_B0_FIXPT            0x007F889F
#define MOD_GENFILTER2_ALG0_STAGE0_B0_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0.99635688846531)
#define MOD_GENFILTER2_ALG0_STAGE0_B0_TYPE             SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GENFILTER2_ALG0_STAGE0_B1_ADDR             15
#define MOD_GENFILTER2_ALG0_STAGE0_B1_FIXPT            0xFF00F45A
#define MOD_GENFILTER2_ALG0_STAGE0_B1_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(-1.99254305630704)
#define MOD_GENFILTER2_ALG0_STAGE0_B1_TYPE             SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GENFILTER2_ALG0_STAGE0_B2_ADDR             16
#define MOD_GENFILTER2_ALG0_STAGE0_B2_FIXPT            0x007F889F
#define MOD_GENFILTER2_ALG0_STAGE0_B2_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0.99635688846531)
#define MOD_GENFILTER2_ALG0_STAGE0_B2_TYPE             SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GENFILTER2_ALG0_STAGE0_A0_ADDR             17
#define MOD_GENFILTER2_ALG0_STAGE0_A0_FIXPT            0x00FF0BA6
#define MOD_GENFILTER2_ALG0_STAGE0_A0_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(1.99254305630704)
#define MOD_GENFILTER2_ALG0_STAGE0_A0_TYPE             SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GENFILTER2_ALG0_STAGE0_A1_ADDR             18
#define MOD_GENFILTER2_ALG0_STAGE0_A1_FIXPT            0xFF80EEC2
#define MOD_GENFILTER2_ALG0_STAGE0_A1_VALUE            SIGMASTUDIOTYPE_FIXPOINT_CONVERT(-0.992713776930619)
#define MOD_GENFILTER2_ALG0_STAGE0_A1_TYPE             SIGMASTUDIOTYPE_FIXPOINT

/* Module Gen 1st Order1_2 - General (1st order)*/
#define MOD_GEN1STORDER1_2_COUNT                       3
#define MOD_GEN1STORDER1_2_DEVICE                      "IC1"
#define MOD_GEN1STORDER1_2_ALG0_PARAMB00_ADDR          19
#define MOD_GEN1STORDER1_2_ALG0_PARAMB00_FIXPT         0x00000885
#define MOD_GEN1STORDER1_2_ALG0_PARAMB00_VALUE         SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0.000259998900530634)
#define MOD_GEN1STORDER1_2_ALG0_PARAMB00_TYPE          SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GEN1STORDER1_2_ALG0_PARAMB10_ADDR          20
#define MOD_GEN1STORDER1_2_ALG0_PARAMB10_FIXPT         0x00000000
#define MOD_GEN1STORDER1_2_ALG0_PARAMB10_VALUE         SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0)
#define MOD_GEN1STORDER1_2_ALG0_PARAMB10_TYPE          SIGMASTUDIOTYPE_FIXPOINT
#define MOD_GEN1STORDER1_2_ALG0_PARAMA00_ADDR          21
#define MOD_GEN1STORDER1_2_ALG0_PARAMA00_FIXPT         0x007FF77A
#define MOD_GEN1STORDER1_2_ALG0_PARAMA00_VALUE         SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0.999740001099469)
#define MOD_GEN1STORDER1_2_ALG0_PARAMA00_TYPE          SIGMASTUDIOTYPE_FIXPOINT

/* Module Gain2 - Gain*/
#define MOD_GAIN2_COUNT                                1
#define MOD_GAIN2_DEVICE                               "IC1"
#define MOD_GAIN2_GAIN1940ALGNS2_ADDR                  22
#define MOD_GAIN2_GAIN1940ALGNS2_FIXPT                 0x000CCCCC
#define MOD_GAIN2_GAIN1940ALGNS2_VALUE                 SIGMASTUDIOTYPE_FIXPOINT_CONVERT(0.1)
#define MOD_GAIN2_GAIN1940ALGNS2_TYPE                  SIGMASTUDIOTYPE_FIXPOINT

/* Module ReadBack1 - DSP Readback*/
#define MOD_READBACK1_COUNT                            2
#define MOD_READBACK1_DEVICE                           "IC1"
#define MOD_READBACK1_ALG0_VAL0_ADDR                   2074
#define MOD_READBACK1_ALG0_VAL0_VALUES                 SIGMASTUDIOTYPE_SPECIAL(0x00D6)
#define MOD_READBACK1_ALG0_VAL0_TYPE                   SIGMASTUDIOTYPE_SPECIAL
#define MOD_READBACK1_ALG0_VAL0_READBACK_ADDR          0
#define MOD_READBACK1_ALG0_VAL1_ADDR                   2074
#define MOD_READBACK1_ALG0_VAL1_VALUE                  SIGMASTUDIOTYPE_5_19_CONVERT(0)
#define MOD_READBACK1_ALG0_VAL1_TYPE                   SIGMASTUDIOTYPE_5_19

/* Module ReadBack3 - DSP Readback*/
#define MOD_READBACK3_COUNT                            2
#define MOD_READBACK3_DEVICE                           "IC1"
#define MOD_READBACK3_ALG0_VAL0_ADDR                   2074
#define MOD_READBACK3_ALG0_VAL0_VALUES                 SIGMASTUDIOTYPE_SPECIAL(0x00EE)
#define MOD_READBACK3_ALG0_VAL0_TYPE                   SIGMASTUDIOTYPE_SPECIAL
#define MOD_READBACK3_ALG0_VAL0_READBACK_ADDR          0
#define MOD_READBACK3_ALG0_VAL1_ADDR                   2074
#define MOD_READBACK3_ALG0_VAL1_VALUE                  SIGMASTUDIOTYPE_5_19_CONVERT(0)
#define MOD_READBACK3_ALG0_VAL1_TYPE                   SIGMASTUDIOTYPE_5_19

/* Module ReadBack2 - DSP Readback*/
#define MOD_READBACK2_COUNT                            2
#define MOD_READBACK2_DEVICE                           "IC1"
#define MOD_READBACK2_ALG0_VAL0_ADDR                   2074
#define MOD_READBACK2_ALG0_VAL0_VALUES                 SIGMASTUDIOTYPE_SPECIAL(0x00E2)
#define MOD_READBACK2_ALG0_VAL0_TYPE                   SIGMASTUDIOTYPE_SPECIAL
#define MOD_READBACK2_ALG0_VAL0_READBACK_ADDR          0
#define MOD_READBACK2_ALG0_VAL1_ADDR                   2074
#define MOD_READBACK2_ALG0_VAL1_VALUE                  SIGMASTUDIOTYPE_5_19_CONVERT(0)
#define MOD_READBACK2_ALG0_VAL1_TYPE                   SIGMASTUDIOTYPE_5_19

/* Module ReadBack4 - DSP Readback*/
#define MOD_READBACK4_COUNT                            2
#define MOD_READBACK4_DEVICE                           "IC1"
#define MOD_READBACK4_ALG0_VAL0_ADDR                   2074
#define MOD_READBACK4_ALG0_VAL0_VALUES                 SIGMASTUDIOTYPE_SPECIAL(0x00FA)
#define MOD_READBACK4_ALG0_VAL0_TYPE                   SIGMASTUDIOTYPE_SPECIAL
#define MOD_READBACK4_ALG0_VAL0_READBACK_ADDR          0
#define MOD_READBACK4_ALG0_VAL1_ADDR                   2074
#define MOD_READBACK4_ALG0_VAL1_VALUE                  SIGMASTUDIOTYPE_5_19_CONVERT(0)
#define MOD_READBACK4_ALG0_VAL1_TYPE                   SIGMASTUDIOTYPE_5_19

#endif
