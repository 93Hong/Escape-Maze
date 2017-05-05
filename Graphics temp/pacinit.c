#include "pacman.h"

// 맵 그리기
// 좌표 복붙으로 위치만 변경
void init_3d_objects(void) {

	polygonx1[0] = -3, polygony1[0] = -2;
	polygonx2[0] = 4, polygony2[0] = -2;
	polygonx3[0] = 4, polygony3[0] = 2;
	polygonx4[0] = -3, polygony4[0] = 2;


	polygonx1[1] = -11, polygony1[1] = -14;
	polygonx2[1] = -2, polygony2[1] = -14;
	polygonx3[1] = -2, polygony3[1] = -13;
	polygonx4[1] = -11, polygony4[1] = -13;


	polygonx1[2] = 0, polygony1[2] = -14;
	polygonx2[2] = 1, polygony2[2] = -14;
	polygonx3[2] = 1, polygony3[2] = -11;
	polygonx4[2] = 0, polygony4[2] = -11;


	polygonx1[3] = 3, polygony1[3] = -14;
	polygonx2[3] = 12, polygony2[3] = -14;
	polygonx3[3] = 12, polygony3[3] = -13;
	polygonx4[3] = 3, polygony4[3] = -13;


	polygonx1[4] = -6, polygony1[4] = -13;
	polygonx2[4] = -5, polygony2[4] = -13;
	polygonx3[4] = -5, polygony3[4] = -10;
	polygonx4[4] = -6, polygony4[4] = -10;


	polygonx1[5] = 6, polygony1[5] = -13;
	polygonx2[5] = 7, polygony2[5] = -13;
	polygonx3[5] = 7, polygony3[5] = -10;
	polygonx4[5] = 6, polygony4[5] = -10;


	polygonx1[6] = -13, polygony1[6] = -11;
	polygonx2[6] = -11, polygony2[6] = -11;
	polygonx3[6] = -11, polygony3[6] = -10;
	polygonx4[6] = -13, polygony4[6] = -10;


	polygonx1[7] = -3, polygony1[7] = -11;
	polygonx2[7] = 4, polygony2[7] = -11;
	polygonx3[7] = 4, polygony3[7] = -10;
	polygonx4[7] = -3, polygony4[7] = -10;


	polygonx1[8] = 12, polygony1[8] = -11;
	polygonx2[8] = 14, polygony2[8] = -11;
	polygonx3[8] = 14, polygony3[8] = -10;
	polygonx4[8] = 12, polygony4[8] = -10;


	polygonx1[9] = -9, polygony1[9] = -11;
	polygonx2[9] = -8, polygony2[9] = -11;
	polygonx3[9] = -8, polygony3[9] = -8;
	polygonx4[9] = -9, polygony4[9] = -8;


	polygonx1[10] = 9, polygony1[10] = -11;
	polygonx2[10] = 10, polygony2[10] = -11;
	polygonx3[10] = 10, polygony3[10] = -8;
	polygonx4[10] = 9, polygony4[10] = -8;


	polygonx1[11] = -11, polygony1[11] = -8;
	polygonx2[11] = -8, polygony2[11] = -8;
	polygonx3[11] = -8, polygony3[11] = -7;
	polygonx4[11] = -11, polygony4[11] = -7;


	polygonx1[12] = -6, polygony1[12] = -8;
	polygonx2[12] = -2, polygony2[12] = -8;
	polygonx3[12] = -2, polygony3[12] = -7;
	polygonx4[12] = -6, polygony4[12] = -7;


	polygonx1[13] = 0, polygony1[13] = -8;
	polygonx2[13] = 1, polygony2[13] = -8;
	polygonx3[13] = 1, polygony3[13] = -5;
	polygonx4[13] = 0, polygony4[13] = -5;


	polygonx1[14] = 3, polygony1[14] = -8;
	polygonx2[14] = 7, polygony2[14] = -8;
	polygonx3[14] = 7, polygony3[14] = -7;
	polygonx4[14] = 3, polygony4[14] = -7;


	polygonx1[15] = 9, polygony1[15] = -8;
	polygonx2[15] = 12, polygony2[15] = -8;
	polygonx3[15] = 12, polygony3[15] = -7;
	polygonx4[15] = 9, polygony4[15] = -7;


	polygonx1[16] = -13, polygony1[16] = -5;
	polygonx2[16] = -8, polygony2[16] = -5;
	polygonx3[16] = -8, polygony3[16] = -4;
	polygonx4[16] = -13, polygony4[16] = -4;


	polygonx1[17] = -3, polygony1[17] = -5;
	polygonx2[17] = 4, polygony2[17] = -5;
	polygonx3[17] = 4, polygony3[17] = -4;
	polygonx4[17] = -3, polygony4[17] = -4;


	polygonx1[18] = 9, polygony1[18] = -5;
	polygonx2[18] = 14, polygony2[18] = -5;
	polygonx3[18] = 14, polygony3[18] = -4;
	polygonx4[18] = 9, polygony4[18] = -4;


	polygonx1[19] = -9, polygony1[19] = -4;
	polygonx2[19] = -8, polygony2[19] = -4;
	polygonx3[19] = -8, polygony3[19] = -2;
	polygonx4[19] = -9, polygony4[19] = -2;


	polygonx1[20] = -6, polygony1[20] = -5;
	polygonx2[20] = -5, polygony2[20] = -5;
	polygonx3[20] = -5, polygony3[20] = -1;
	polygonx4[20] = -6, polygony4[20] = -1;


	polygonx1[21] = 6, polygony1[21] = -5;
	polygonx2[21] = 7, polygony2[21] = -5;
	polygonx3[21] = 7, polygony3[21] = -1;
	polygonx4[21] = 6, polygony4[21] = -1;


	polygonx1[22] = 9, polygony1[22] = -4;
	polygonx2[22] = 10, polygony2[22] = -4;
	polygonx3[22] = 10, polygony3[22] = -2;
	polygonx4[22] = 9, polygony4[22] = -2;


	polygonx1[23] = -13, polygony1[23] = -2;
	polygonx2[23] = -8, polygony2[23] = -2;
	polygonx3[23] = -8, polygony3[23] = -1;
	polygonx4[23] = -13, polygony4[23] = -1;


	polygonx1[24] = 9, polygony1[24] = -2;
	polygonx2[24] = 14, polygony2[24] = -2;
	polygonx3[24] = 14, polygony3[24] = -1;
	polygonx4[24] = 9, polygony4[24] = -1;


	polygonx1[25] = -13, polygony1[25] = 1;
	polygonx2[25] = -8, polygony2[25] = 1;
	polygonx3[25] = -8, polygony3[25] = 2;
	polygonx4[25] = -13, polygony4[25] = 2;


	polygonx1[26] = 9, polygony1[26] = 1;
	polygonx2[26] = 14, polygony2[26] = 1;
	polygonx3[26] = 14, polygony3[26] = 2;
	polygonx4[26] = 9, polygony4[26] = 2;


	polygonx1[27] = -9, polygony1[27] = 2;
	polygonx2[27] = -8, polygony2[27] = 2;
	polygonx3[27] = -8, polygony3[27] = 4;
	polygonx4[27] = -9, polygony4[27] = 4;


	polygonx1[28] = -6, polygony1[28] = 1;
	polygonx2[28] = -5, polygony2[28] = 1;
	polygonx3[28] = -5, polygony3[28] = 8;
	polygonx4[28] = -6, polygony4[28] = 8;


	polygonx1[29] = 6, polygony1[29] = 1;
	polygonx2[29] = 7, polygony2[29] = 1;
	polygonx3[29] = 7, polygony3[29] = 8;
	polygonx4[29] = 6, polygony4[29] = 8;


	polygonx1[30] = 9, polygony1[30] = 2;
	polygonx2[30] = 10, polygony2[30] = 2;
	polygonx3[30] = 10, polygony3[30] = 4;
	polygonx4[30] = 9, polygony4[30] = 4;


	polygonx1[31] = -13, polygony1[31] = 4;
	polygonx2[31] = -8, polygony2[31] = 4;
	polygonx3[31] = -8, polygony3[31] = 5;
	polygonx4[31] = -13, polygony4[31] = 5;


	polygonx1[32] = -5, polygony1[32] = 4;
	polygonx2[32] = -2, polygony2[32] = 4;
	polygonx3[32] = -2, polygony3[32] = 5;
	polygonx4[32] = -5, polygony4[32] = 5;


	polygonx1[33] = 0, polygony1[33] = 4;
	polygonx2[33] = 1, polygony2[33] = 4;
	polygonx3[33] = 1, polygony3[33] = 7;
	polygonx4[33] = 0, polygony4[33] = 7;


	polygonx1[34] = 3, polygony1[34] = 4;
	polygonx2[34] = 6, polygony2[34] = 4;
	polygonx3[34] = 6, polygony3[34] = 5;
	polygonx4[34] = 3, polygony4[34] = 5;


	polygonx1[35] = 9, polygony1[35] = 4;
	polygonx2[35] = 14, polygony2[35] = 4;
	polygonx3[35] = 14, polygony3[35] = 5;
	polygonx4[35] = 9, polygony4[35] = 5;


	polygonx1[36] = -11, polygony1[36] = 7;
	polygonx2[36] = -8, polygony2[36] = 7;
	polygonx3[36] = -8, polygony3[36] = 8;
	polygonx4[36] = -11, polygony4[36] = 8;


	polygonx1[37] = -3, polygony1[37] = 7;
	polygonx2[37] = 4, polygony2[37] = 7;
	polygonx3[37] = 4, polygony3[37] = 8;
	polygonx4[37] = -3, polygony4[37] = 8;


	polygonx1[38] = 9, polygony1[38] = 7;
	polygonx2[38] = 12, polygony2[38] = 7;
	polygonx3[38] = 12, polygony3[38] = 8;
	polygonx4[38] = 9, polygony4[38] = 8;


	polygonx1[39] = -11, polygony1[39] = 10;
	polygonx2[39] = -8, polygony2[39] = 10;
	polygonx3[39] = -8, polygony3[39] = 12;
	polygonx4[39] = -11, polygony4[39] = 12;


	polygonx1[40] = -6, polygony1[40] = 10;
	polygonx2[40] = -2, polygony2[40] = 10;
	polygonx3[40] = -2, polygony3[40] = 12;
	polygonx4[40] = -6, polygony4[40] = 12;


	polygonx1[41] = 0, polygony1[41] = 10;
	polygonx2[41] = 1, polygony2[41] = 10;
	polygonx3[41] = 1, polygony3[41] = 14;
	polygonx4[41] = 0, polygony4[41] = 14;


	polygonx1[42] = 3, polygony1[42] = 10;
	polygonx2[42] = 7, polygony2[42] = 10;
	polygonx3[42] = 7, polygony3[42] = 12;
	polygonx4[42] = 3, polygony4[42] = 12;


	polygonx1[43] = 9, polygony1[43] = 10;
	polygonx2[43] = 12, polygony2[43] = 10;
	polygonx3[43] = 12, polygony3[43] = 12;
	polygonx4[43] = 9, polygony4[43] = 12;


	polygonx1[44] = -14, polygony1[44] = -17;
	polygonx2[44] = 15, polygony2[44] = -17;
	polygonx3[44] = 15, polygony3[44] = -16;
	polygonx4[44] = -14, polygony4[44] = -16;


	polygonx1[45] = 14, polygony1[45] = -16;
	polygonx2[45] = 15, polygony2[45] = -16;
	polygonx3[45] = 15, polygony3[45] = -1;
	polygonx4[45] = 14, polygony4[45] = -1;


	polygonx1[46] = 14, polygony1[46] = 1;
	polygonx2[46] = 15, polygony2[46] = 1;
	polygonx3[46] = 15, polygony3[46] = 14;
	polygonx4[46] = 14, polygony4[46] = 14;


	polygonx1[47] = -14, polygony1[47] = 14;
	polygonx2[47] = 15, polygony2[47] = 14;
	polygonx3[47] = 15, polygony3[47] = 15;
	polygonx4[47] = -14, polygony4[47] = 15;


	polygonx1[48] = -14, polygony1[48] = -16;
	polygonx2[48] = -13, polygony2[48] = -16;
	polygonx3[48] = -13, polygony3[48] = -1;
	polygonx4[48] = -14, polygony4[48] = -1;


	polygonx1[49] = -14, polygony1[49] = 1;
	polygonx2[49] = -13, polygony2[49] = 1;
	polygonx3[49] = -13, polygony3[49] = 14;
	polygonx4[49] = -14, polygony4[49] = 14;

	/////////////////////////////////////////////////////////////////
	/*1*/
	foodx[1] = -12, foodz[1] = -15;
	foodx[2] = -11, foodz[2] = -15;
	foodx[3] = -10, foodz[3] = -15;
	foodx[4] = -9, foodz[4] = -15;
	foodx[5] = -8, foodz[5] = -15;
	foodx[6] = -7, foodz[6] = -15;
	foodx[7] = -6, foodz[7] = -15;
	foodx[8] = -5, foodz[8] = -15;
	foodx[9] = -4, foodz[9] = -15;
	foodx[10] = -3, foodz[10] = -15;
	foodx[11] = -2, foodz[11] = -15;
	foodx[12] = -1, foodz[12] = -15;
	foodx[13] = 0, foodz[13] = -15;
	foodx[14] = 1, foodz[14] = -15;
	foodx[15] = 2, foodz[15] = -15;
	foodx[16] = 3, foodz[16] = -15;
	foodx[17] = 4, foodz[17] = -15;
	foodx[18] = 5, foodz[18] = -15;
	foodx[19] = 6, foodz[19] = -15;
	foodx[20] = 7, foodz[20] = -15;
	foodx[21] = 8, foodz[21] = -15;
	foodx[22] = 9, foodz[22] = -15;
	foodx[23] = 10, foodz[23] = -15;
	foodx[24] = 11, foodz[24] = -15;
	foodx[25] = 12, foodz[25] = -15;
	foodx[26] = 13, foodz[26] = -15;

	/*2*/
	foodx[27] = -12, foodz[27] = -14;
	foodx[28] = -1, foodz[28] = -14;
	foodx[29] = 2, foodz[29] = -14;
	foodx[30] = 13, foodz[30] = -14;

	/*3*/
	foodx[31] = -12, foodz[31] = -13;
	foodx[32] = -1, foodz[32] = -13;
	foodx[33] = 2, foodz[33] = -13;
	foodx[34] = 13, foodz[34] = -13;

	/*4*/
	foodx[35] = -12, foodz[35] = -12;
	foodx[36] = -11, foodz[36] = -12;
	foodx[37] = -10, foodz[37] = -12;
	foodx[38] = -9, foodz[38] = -12;
	foodx[39] = -8, foodz[39] = -12;
	foodx[40] = -7, foodz[40] = -12;
	foodx[41] = -4, foodz[41] = -12;
	foodx[42] = -3, foodz[42] = -12;
	foodx[43] = -2, foodz[43] = -12;
	foodx[44] = -1, foodz[44] = -12;
	foodx[45] = 2, foodz[45] = -12;
	foodx[46] = 3, foodz[46] = -12;
	foodx[47] = 4, foodz[47] = -12;
	foodx[48] = 5, foodz[48] = -12;
	foodx[49] = 8, foodz[49] = -12;
	foodx[50] = 9, foodz[50] = -12;
	foodx[51] = 10, foodz[51] = -12;
	foodx[100] = 11, foodz[100] = -12;
	foodx[52] = 12, foodz[52] = -12;
	foodx[53] = 13, foodz[53] = -12;

	/*5*/
	foodx[54] = -10, foodz[54] = -11;
	foodx[55] = -7, foodz[55] = -11;
	foodx[56] = -4, foodz[56] = -11;
	foodx[57] = 5, foodz[57] = -11;
	foodx[58] = 8, foodz[58] = -11;
	foodx[59] = 11, foodz[59] = -11;

	/*6*/
	foodx[60] = -10, foodz[60] = -10;
	foodx[61] = -7, foodz[61] = -10;
	foodx[62] = -4, foodz[62] = -10;
	foodx[63] = 5, foodz[63] = -10;
	foodx[64] = 8, foodz[64] = -10;
	foodx[65] = 11, foodz[65] = -10;

	/*7*/
	foodx[66] = -12, foodz[66] = -9;
	foodx[67] = -11, foodz[67] = -9;
	foodx[68] = -10, foodz[68] = -9;
	foodx[69] = -7, foodz[69] = -9;
	foodx[70] = -6, foodz[70] = -9;
	foodx[71] = -5, foodz[71] = -9;
	foodx[72] = -4, foodz[72] = -9;
	foodx[73] = -3, foodz[73] = -9;
	foodx[74] = -2, foodz[74] = -9;
	foodx[75] = 1, foodz[75] = -9;
	foodx[76] = 0, foodz[76] = -9;
	foodx[77] = 1, foodz[77] = -9;
	foodx[78] = 2, foodz[78] = -9;
	foodx[79] = 3, foodz[79] = -9;
	foodx[80] = 4, foodz[80] = -9;
	foodx[81] = 5, foodz[81] = -9;
	foodx[82] = 6, foodz[82] = -9;
	foodx[83] = 7, foodz[83] = -9;
	foodx[84] = 8, foodz[84] = -9;
	foodx[85] = 11, foodz[85] = -9;
	foodx[86] = 12, foodz[86] = -9;
	foodx[87] = 13, foodz[87] = -9;

	/*8*/
	foodx[88] = -12, foodz[88] = -8;
	foodx[89] = -7, foodz[89] = -8;
	foodx[90] = -1, foodz[90] = -8;
	foodx[91] = 2, foodz[91] = -8;
	foodx[92] = 8, foodz[92] = -8;
	foodx[93] = 13, foodz[93] = -8;

	/*9*/
	foodx[94] = -12, foodz[94] = -7;
	foodx[95] = -7, foodz[95] = -7;
	foodx[96] = -1, foodz[96] = -7;
	foodx[97] = 2, foodz[97] = -7;
	foodx[98] = 8, foodz[98] = -7;
	foodx[99] = 13, foodz[99] = -7;

	/*10*/
	foodx[101] = -12, foodz[101] = -6;
	foodx[102] = -11, foodz[102] = -6;
	foodx[103] = -10, foodz[103] = -6;
	foodx[104] = -9, foodz[104] = -6;
	foodx[105] = -8, foodz[105] = -6;
	foodx[106] = -7, foodz[106] = -6;
	foodx[107] = -6, foodz[107] = -6;
	foodx[108] = -5, foodz[108] = -6;
	foodx[109] = -4, foodz[109] = -6;
	foodx[110] = -3, foodz[110] = -6;
	foodx[111] = -2, foodz[111] = -6;
	foodx[112] = -1, foodz[112] = -6;
	foodx[113] = 2, foodz[113] = -6;
	foodx[114] = 3, foodz[114] = -6;
	foodx[115] = 4, foodz[115] = -6;
	foodx[116] = 5, foodz[116] = -6;
	foodx[117] = 6, foodz[117] = -6;
	foodx[118] = 7, foodz[118] = -6;
	foodx[119] = 8, foodz[119] = -6;
	foodx[120] = 9, foodz[120] = -6;
	foodx[121] = 10, foodz[121] = -6;
	foodx[122] = 11, foodz[122] = -6;
	foodx[123] = 12, foodz[123] = -6;
	foodx[124] = 13, foodz[124] = -6;

	/*11*/
	foodx[125] = -7, foodz[125] = -5;
	foodx[126] = -4, foodz[126] = -5;
	foodx[127] = 5, foodz[127] = -5;
	foodx[128] = 8, foodz[128] = -5;

	/*12*/
	foodx[129] = -7, foodz[129] = -4;
	foodx[130] = -4, foodz[130] = -4;
	foodx[131] = 5, foodz[131] = -4;
	foodx[132] = 8, foodz[132] = -4;

	/*13*/
	foodx[133] = -7, foodz[133] = -3;
	foodx[134] = -4, foodz[134] = -3;
	foodx[135] = -3, foodz[135] = -3;
	foodx[136] = -2, foodz[136] = -3;
	foodx[137] = -1, foodz[137] = -3;
	foodx[138] = 0, foodz[138] = -3;
	foodx[139] = 1, foodz[139] = -3;
	foodx[140] = 2, foodz[140] = -3;
	foodx[141] = 3, foodz[141] = -3;
	foodx[142] = 4, foodz[142] = -3;
	foodx[143] = 5, foodz[143] = -3;
	foodx[145] = 8, foodz[145] = -3;

	/*14*/
	foodx[146] = -7, foodz[146] = -2;
	foodx[147] = -4, foodz[147] = -2;
	foodx[148] = 5, foodz[148] = -2;
	foodx[149] = 8, foodz[149] = -2;

	/*15*/
	foodx[150] = -7, foodz[150] = -1;
	foodx[151] = -4, foodz[151] = -1;
	foodx[152] = 5, foodz[152] = -1;
	foodx[153] = 8, foodz[153] = -1;

	/*16*/
	foodx[164] = -7, foodz[164] = 0;
	foodx[165] = -6, foodz[165] = 0;
	foodx[166] = -5, foodz[166] = 0;
	foodx[167] = -4, foodz[167] = 0;
	foodx[168] = 5, foodz[168] = 0;
	foodx[169] = 6, foodz[169] = 0;
	foodx[170] = 7, foodz[170] = 0;
	foodx[171] = 8, foodz[171] = 0;

	/*17*/
	foodx[172] = -7, foodz[172] = 1;
	foodx[173] = -4, foodz[173] = 1;
	foodx[174] = 5, foodz[174] = 1;
	foodx[175] = 8, foodz[175] = 1;

	/*18*/
	foodx[176] = -7, foodz[176] = 2;
	foodx[177] = -4, foodz[177] = 2;
	foodx[178] = 5, foodz[178] = 2;
	foodx[179] = 8, foodz[179] = 2;

	/*19*/
	foodx[180] = -7, foodz[180] = 3;
	foodx[181] = -4, foodz[181] = 3;
	foodx[182] = -3, foodz[182] = 3;
	foodx[183] = -2, foodz[183] = 3;
	foodx[184] = -1, foodz[184] = 3;
	foodx[185] = 0, foodz[185] = 3;
	foodx[186] = 1, foodz[186] = 3;
	foodx[187] = 2, foodz[187] = 3;
	foodx[188] = 3, foodz[188] = 3;
	foodx[189] = 4, foodz[189] = 3;
	foodx[190] = 5, foodz[190] = 3;
	foodx[192] = 8, foodz[192] = 3;

	/*20*/
	foodx[193] = -7, foodz[193] = 4;
	foodx[194] = -1, foodz[194] = 4;
	foodx[195] = 2, foodz[195] = 4;
	foodx[196] = 8, foodz[196] = 4;

	/*21*/
	foodx[197] = -7, foodz[197] = 5;
	foodx[198] = -1, foodz[198] = 5;
	foodx[199] = 2, foodz[199] = 5;
	foodx[200] = 8, foodz[200] = 5;

	/*22*/
	foodx[201] = -12, foodz[201] = 6;
	foodx[202] = -11, foodz[202] = 6;
	foodx[203] = -10, foodz[203] = 6;
	foodx[204] = -9, foodz[204] = 6;
	foodx[205] = -8, foodz[205] = 6;
	foodx[206] = -7, foodz[206] = 6;
	foodx[207] = -4, foodz[207] = 6;
	foodx[208] = -3, foodz[208] = 6;
	foodx[209] = -2, foodz[209] = 6;
	foodx[210] = -1, foodz[210] = 6;
	foodx[211] = 2, foodz[211] = 6;
	foodx[212] = 3, foodz[212] = 6;
	foodx[213] = 4, foodz[213] = 6;
	foodx[214] = 5, foodz[214] = 6;
	foodx[215] = 8, foodz[215] = 6;
	foodx[216] = 9, foodz[216] = 6;
	foodx[217] = 10, foodz[217] = 6;
	foodx[218] = 11, foodz[218] = 6;
	foodx[219] = 12, foodz[219] = 6;
	foodx[220] = 13, foodz[220] = 6;

	/*23*/
	foodx[231] = -12, foodz[231] = 7;
	foodx[232] = -7, foodz[232] = 7;
	foodx[233] = -4, foodz[233] = 7;
	foodx[234] = 5, foodz[234] = 7;
	foodx[235] = 8, foodz[235] = 7;
	foodx[236] = 13, foodz[236] = 7;

	/*24*/
	foodx[237] = -12, foodz[237] = 8;
	foodx[238] = -7, foodz[238] = 8;
	foodx[239] = -4, foodz[239] = 8;
	foodx[240] = 5, foodz[240] = 8;
	foodx[241] = 8, foodz[241] = 8;
	foodx[242] = 13, foodz[242] = 8;

	/*25*/
	foodx[243] = -12, foodz[243] = 9;
	foodx[244] = -11, foodz[244] = 9;
	foodx[245] = -10, foodz[245] = 9;
	foodx[246] = -9, foodz[246] = 9;
	foodx[247] = -8, foodz[247] = 9;
	foodx[248] = -7, foodz[248] = 9;
	foodx[249] = -6, foodz[249] = 9;
	foodx[251] = -5, foodz[251] = 9;
	foodx[252] = -4, foodz[252] = 9;
	foodx[253] = -3, foodz[253] = 9;
	foodx[254] = -2, foodz[254] = 9;
	foodx[255] = -1, foodz[255] = 9;
	foodx[256] = 0, foodz[256] = 9;
	foodx[257] = 1, foodz[257] = 9;
	foodx[258] = 2, foodz[258] = 9;
	foodx[259] = 3, foodz[259] = 9;
	foodx[260] = 4, foodz[260] = 9;
	foodx[261] = 5, foodz[261] = 9;
	foodx[262] = 6, foodz[262] = 9;
	foodx[263] = 7, foodz[263] = 9;
	foodx[264] = 8, foodz[264] = 9;
	foodx[265] = 9, foodz[265] = 9;
	foodx[266] = 10, foodz[266] = 9;
	foodx[267] = 11, foodz[267] = 9;
	foodx[268] = 12, foodz[268] = 9;
	foodx[269] = 13, foodz[269] = 9;

	/*26*/
	foodx[271] = -12, foodz[271] = 10;
	foodx[272] = -7, foodz[272] = 10;
	foodx[273] = -1, foodz[273] = 10;
	foodx[274] = 2, foodz[274] = 10;
	foodx[275] = 8, foodz[275] = 10;
	foodx[276] = 13, foodz[276] = 10;

	/*27*/
	foodx[277] = -12, foodz[277] = 11;
	foodx[278] = -7, foodz[278] = 11;
	foodx[279] = -1, foodz[279] = 11;
	foodx[280] = 2, foodz[280] = 11;
	foodx[281] = 8, foodz[281] = 11;
	foodx[282] = 13, foodz[282] = 11;

	/*28*/
	foodx[283] = -12, foodz[283] = 12;
	foodx[284] = -7, foodz[284] = 12;
	foodx[285] = -1, foodz[285] = 12;
	foodx[286] = 2, foodz[286] = 12;
	foodx[287] = 8, foodz[287] = 12;
	foodx[288] = 13, foodz[288] = 12;

	/*29*/
	foodx[289] = -12, foodz[289] = 13;
	foodx[290] = -11, foodz[290] = 13;
	foodx[291] = -10, foodz[291] = 13;
	foodx[292] = -9, foodz[292] = 13;
	foodx[293] = -8, foodz[293] = 13;
	foodx[294] = -7, foodz[294] = 13;
	foodx[295] = -6, foodz[295] = 13;
	foodx[296] = -5, foodz[296] = 13;
	foodx[297] = -4, foodz[297] = 13;
	foodx[298] = -3, foodz[298] = 13;
	foodx[299] = -2, foodz[299] = 13;
	foodx[300] = -1, foodz[300] = 13;
	foodx[301] = 2, foodz[301] = 13;
	foodx[302] = 3, foodz[302] = 13;
	foodx[303] = 4, foodz[303] = 13;
	foodx[304] = 5, foodz[304] = 13;
	foodx[305] = 6, foodz[305] = 13;
	foodx[306] = 7, foodz[306] = 13;
	foodx[307] = 8, foodz[307] = 13;
	foodx[308] = 9, foodz[308] = 13;
	foodx[309] = 10, foodz[309] = 13;
	foodx[310] = 11, foodz[310] = 13;
	foodx[311] = 12, foodz[311] = 13;
	foodx[312] = 13, foodz[312] = 13;

	foodx[144] = 0, foodz[144] = 0, foodloop = 0;
	foodx[191] = 0, foodz[191] = 0, foodloop = 0;
}

void tormaysmallinnus(void) {
	if (pacpos_x <= -13 && pacpos_z >= -0.01 && pacpos_z <= +0.01) pacpos_x = 13;
	if (pacpos_x >= 14 && pacpos_z >= -0.01 && pacpos_z <= +0.01) pacpos_x = -12;

	if (pacpos_x <= -12 && pacpos_z <= -15) {
		direction = 0;
		seta = 1;
	}
	if (pacpos_x >= -1 - 0.01 && pacpos_x <= -1 + 0.01 && pacpos_z >= -15 - 0.01 && pacpos_z <= -15 + 0.01) {
		direction = 0;
		seta = 2;
	}
	if (pacpos_x >= 2 - 0.01 && pacpos_x <= 2 + 0.01 && pacpos_z >= -15 - 0.01 && pacpos_z <= -15 + 0.01) {
		direction = 0;
		seta = 3;
	}
	if (pacpos_x >= 13 - 0.01 && pacpos_x <= 13 + 0.01 && pacpos_z >= -15 - 0.01 && pacpos_z <= -15 + 0.01) {
		direction = 0;
		seta = 4;
	}
	if (pacpos_x >= -12 - 0.01 && pacpos_x <= -12 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01) {
		direction = 0;
		seta = 5;
	}
	if (pacpos_x >= -7 - 0.01 && pacpos_x <= -7 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01) {
		direction = 0;
		seta = 6;
	}
	if (pacpos_x >= -4 - 0.01 && pacpos_x <= -4 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01) {
		direction = 0;
		seta = 7;
	}
	if (pacpos_x >= -1 - 0.01 && pacpos_x <= -1 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01)	{
		direction = 0;
		seta = 8;
	}
	if (pacpos_x >= 2 - 0.01 && pacpos_x <= 2 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01) {
		direction = 0;
		seta = 9;
	}
	if (pacpos_x >= 5 - 0.01 && pacpos_x <= 5 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01) {
		direction = 0;
		seta = 10;
	}
	if (pacpos_x >= 8 - 0.01 && pacpos_x <= 8 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01) {
		direction = 0;
		seta = 11;
	}
	if (pacpos_x >= 13 - 0.01 && pacpos_x <= 13 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01) {
		direction = 0;
		seta = 12;
	}
	if (pacpos_x >= -12 - 0.01 && pacpos_x <= -12 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01) {
		direction = 0;
		seta = 13;
	}
	if (pacpos_x >= -10 - 0.01 && pacpos_x <= -10 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01)	{
		direction = 0;
		seta = 14;
	}
	if (pacpos_x >= -7 - 0.01 && pacpos_x <= -7 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01) {
		direction = 0;
		seta = 15;
	}
	if (pacpos_x >= -4 - 0.01 && pacpos_x <= -4 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01) {
		direction = 0;
		seta = 16;
	}
	if (pacpos_x >= -1 - 0.01 && pacpos_x <= -1 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01) {
		direction = 0;
		seta = 17;
	}
	if (pacpos_x >= 2 - 0.01 && pacpos_x <= 2 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01)	{
		direction = 0;
		seta = 17;
	}
	if (pacpos_x >= 5 - 0.01 && pacpos_x <= 5 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01)	{
		direction = 0;
		seta = 19;
	}
	if (pacpos_x >= 8 - 0.01 && pacpos_x <= 8 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01)	{
		direction = 0;
		seta = 20;
	}
	if (pacpos_x >= 11 - 0.01 && pacpos_x <= 11 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01) {
		direction = 0;
		seta = 21;
	}
	if (pacpos_x >= 13 - 0.01 && pacpos_x <= 13 + 0.01 && pacpos_z >= -9 - 0.01 && pacpos_z <= -9 + 0.01) {
		direction = 0;
		seta = 22;
	}
	if (pacpos_x >= -10 - 0.01 && pacpos_x <= -10 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01) {
		direction = 0;
		seta = 23;
	}
	if (pacpos_x >= 11 - 0.01 && pacpos_x <= 11 + 0.01 && pacpos_z >= -12 - 0.01 && pacpos_z <= -12 + 0.01) {
		direction = 0;
		seta = 24;
	}
	if (pacpos_x >= -12 - 0.01 && pacpos_x <= -12 + 0.01 && pacpos_z >= -6 - 0.01 && pacpos_z <= -6 + 0.01)	{
		direction = 0;
		seta = 25;
	}
	if (pacpos_x >= -4 - 0.01 && pacpos_x <= -4 + 0.01 && pacpos_z >= 0 - 0.01 && pacpos_z <= 0 + 0.01)	{
		direction = 0;
		seta = 26;
	}
	if (pacpos_x >= -4 - 0.01 && pacpos_x <= -4 + 0.01 && pacpos_z >= -6 - 0.01 && pacpos_z <= -6 + 0.01) {
		direction = 0;
		seta = 27;
	}
	if (pacpos_x >= -1 - 0.01 && pacpos_x <= -1 + 0.01 && pacpos_z >= -6 - 0.01 && pacpos_z <= -6 + 0.01) {
		direction = 0;
		seta = 28;
	}
	if (pacpos_x >= 2 - 0.01 && pacpos_x <= 2 + 0.01 && pacpos_z >= -6 - 0.01 && pacpos_z <= -6 + 0.01) {
		direction = 0;
		seta = 29;
	}
	if (pacpos_x >= 5 - 0.01 && pacpos_x <= 5 + 0.01 && pacpos_z >= -6 - 0.01 && pacpos_z <= -6 + 0.01)	{
		direction = 0;
		seta = 30;
	}
	if (pacpos_x >= 5 - 0.01 && pacpos_x <= 5 + 0.01 && pacpos_z >= 0 - 0.01 && pacpos_z <= 0 + 0.01) {
		direction = 0;
		seta = 31;
	}
	if (pacpos_x >= 13 - 0.01 && pacpos_x <= 13 + 0.01 && pacpos_z >= -6 - 0.01 && pacpos_z <= -6 + 0.01) {
		direction = 0;
		seta = 32;
	}
	if (pacpos_x >= -4 - 0.01 && pacpos_x <= -4 + 0.01 && pacpos_z >= 3 - 0.01 && pacpos_z <= 3 + 0.01)	{
		direction = 0;
		seta = 33;
	}
	if (pacpos_x >= -1 - 0.01 && pacpos_x <= -1 + 0.01 && pacpos_z >= 3 - 0.01 && pacpos_z <= 3 + 0.01)	{
		direction = 0;
		seta = 34;
	}
	if (pacpos_x >= 2 - 0.01 && pacpos_x <= 2 + 0.01 && pacpos_z >= 3 - 0.01 && pacpos_z <= 3 + 0.01) {
		direction = 0;
		seta = 34;
	}
	if (pacpos_x >= 5 - 0.01 && pacpos_x <= 5 + 0.01 && pacpos_z >= 3 - 0.01 && pacpos_z <= 3 + 0.01) {
		direction = 0;
		seta = 36;
	}
	if (pacpos_x >= -12 - 0.01 && pacpos_x <= -12 + 0.01 && pacpos_z >= 6 - 0.01 && pacpos_z <= 6 + 0.01) {
		direction = 0;
		seta = 37;
	}
	if (pacpos_x >= -7 - 0.01 && pacpos_x <= -7 + 0.01 && pacpos_z >= 6 - 0.01 && pacpos_z <= 6 + 0.01) {
		direction = 0;
		seta = 38;
	}
	if (pacpos_x >= -4 - 0.01 && pacpos_x <= -4 + 0.01 && pacpos_z >= 6 - 0.01 && pacpos_z <= 6 + 0.01)	{
		direction = 0;
		seta = 39;
	}
	if (pacpos_x >= -1 - 0.01 && pacpos_x <= -1 + 0.01 && pacpos_z >= 6 - 0.01 && pacpos_z <= 6 + 0.01)	{
		direction = 0;
		seta = 40;
	}
	if (pacpos_x >= 2 - 0.01 && pacpos_x <= 2 + 0.01 && pacpos_z >= 6 - 0.01 && pacpos_z <= 6 + 0.01) {
		direction = 0;
		seta = 41;
	}
	if (pacpos_x >= 5 - 0.01 && pacpos_x <= 5 + 0.01 && pacpos_z >= 6 - 0.01 && pacpos_z <= 6 + 0.01) {
		direction = 0;
		seta = 42;
	}
	if (pacpos_x >= 8 - 0.01 && pacpos_x <= 8 + 0.01 && pacpos_z >= 6 - 0.01 && pacpos_z <= 6 + 0.01) {
		direction = 0;
		seta = 43;
	}
	if (pacpos_x >= 13 - 0.01 && pacpos_x <= 13 + 0.01 && pacpos_z >= 6 - 0.01 && pacpos_z <= 6 + 0.01)	{
		direction = 0;
		seta = 44;
	}
	if (pacpos_x >= -12 - 0.01 && pacpos_x <= -12 + 0.01 && pacpos_z >= 9 - 0.01 && pacpos_z <= 9 + 0.01) {
		direction = 0;
		seta = 45;
	}
	if (pacpos_x >= -4 - 0.01 && pacpos_x <= -4 + 0.01 && pacpos_z >= 9 - 0.01 && pacpos_z <= 9 + 0.01)	{
		direction = 0;
		seta = 46;
	}
	if (pacpos_x >= -1 - 0.01 && pacpos_x <= -1 + 0.01 && pacpos_z >= 9 - 0.01 && pacpos_z <= 9 + 0.01)	{
		direction = 0;
		seta = 47;
	}
	if (pacpos_x >= 2 - 0.01 && pacpos_x <= 2 + 0.01 && pacpos_z >= 9 - 0.01 && pacpos_z <= 9 + 0.01) {
		direction = 0;
		seta = 48;
	}
	if (pacpos_x >= 5 - 0.01 && pacpos_x <= 5 + 0.01 && pacpos_z >= 9 - 0.01 && pacpos_z <= 9 + 0.01) {
		direction = 0;
		seta = 49;
	}
	if (pacpos_x >= 13 - 0.01 && pacpos_x <= 13 + 0.01 && pacpos_z >= 9 - 0.01 && pacpos_z <= 9 + 0.01) {
		direction = 0;
		seta = 50;
	}
	if (pacpos_x >= -12 - 0.01 && pacpos_x <= -12 + 0.01 && pacpos_z >= 13 - 0.01 && pacpos_z <= 13 + 0.01)	{
		direction = 0;
		seta = 51;
	}
	if (pacpos_x >= -7 - 0.01 && pacpos_x <= -7 + 0.01 && pacpos_z >= 13 - 0.01 && pacpos_z <= 13 + 0.01) {
		direction = 0;
		seta = 52;
	}
	if (pacpos_x >= -1 - 0.01 && pacpos_x <= -1 + 0.01 && pacpos_z >= 13 - 0.01 && pacpos_z <= 13 + 0.01) {
		direction = 0;
		seta = 53;
	}
	if (pacpos_x >= 2 - 0.01 && pacpos_x <= 2 + 0.01 && pacpos_z >= 13 - 0.01 && pacpos_z <= 13 + 0.01)	{
		direction = 0;
		seta = 54;
	}
	if (pacpos_x >= 8 - 0.01 && pacpos_x <= 8 + 0.01 && pacpos_z >= 13 - 0.01 && pacpos_z <= 13 + 0.01) {
		direction = 0;
		seta = 55;
	}
	if (pacpos_x >= 13 - 0.01 && pacpos_x <= 13 + 0.01 && pacpos_z >= 13 - 0.01 && pacpos_z <= 13 + 0.01) {
		direction = 0;
		seta = 56;
	}
	if (pacpos_x >= -7 - 0.01 && pacpos_x <= -7 + 0.01 && pacpos_z >= -6 - 0.01 && pacpos_z <= -6 + 0.01) {
		direction = 0;
		seta = 57;
	}
	if (pacpos_x >= 8 - 0.01 && pacpos_x <= 8 + 0.01 && pacpos_z >= -6 - 0.01 && pacpos_z <= -6 + 0.01) {
		direction = 0;
		seta = 58;
	}
	if (pacpos_x >= -4 - 0.01 && pacpos_x <= -4 + 0.01 && pacpos_z >= -3 - 0.01 && pacpos_z <= -3 + 0.01) {
		direction = 0;
		seta = 59;
	}
	if (pacpos_x >= 5 - 0.01 && pacpos_x <= 5 + 0.01 && pacpos_z >= -3 - 0.01 && pacpos_z <= -3 + 0.01) {
		direction = 0;
		seta = 60;
	}
	if (pacpos_x >= -7 - 0.01 && pacpos_x <= -7 + 0.01 && pacpos_z >= 0 - 0.01 && pacpos_z <= 0 + 0.01) {
		direction = 0;
		seta = 61;
	}
	if (pacpos_x >= 8 - 0.01 && pacpos_x <= 8 + 0.01 && pacpos_z >= 0 - 0.01 && pacpos_z <= 0 + 0.01) {
		direction = 0;
		seta = 62;
	}
	if (pacpos_x >= -7 - 0.01 && pacpos_x <= -7 + 0.01 && pacpos_z >= 9 - 0.01 && pacpos_z <= 9 + 0.01) {
		direction = 0;
		seta = 63;
	}
	if (pacpos_x >= 8 - 0.01 && pacpos_x <= 8 + 0.01 && pacpos_z >= 9 - 0.01 && pacpos_z <= 9 + 0.01) {
		direction = 0;
		seta = 64;
	}
}