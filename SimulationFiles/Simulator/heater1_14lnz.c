/* Linearization */
#include "heater1_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *heater1_linear_model_frame()
{
  return "model linear_heater1\n  parameter Integer n = 0 \"number of states\";\n  parameter Integer p = 0 \"number of inputs\";\n  parameter Integer q = 0 \"number of outputs\";\n"
  "\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[p] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n"
  "  parameter Real B[n, p] = zeros(n, p);%s\n"
  "  parameter Real C[q, n] = zeros(q, n);%s\n"
  "  parameter Real D[q, p] = zeros(q, p);%s\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[p];\n"
  "  output Real y[q];\n"
  "\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_heater1;\n";
}
const char *heater1_linear_model_datarecovery_frame()
{
  return "model linear_heater1\n  parameter Integer n = 0 \"number of states\";\n  parameter Integer p = 0 \"number of inputs\";\n  parameter Integer q = 0 \"number of outputs\";\n  parameter Integer nz = 188 \"data recovery variables\";\n"
  "\n"
  "  parameter Real x0[0] = %s;\n"
  "  parameter Real u0[0] = %s;\n"
  "  parameter Real z0[188] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n"
  "  parameter Real B[n, p] = zeros(n, p);%s\n"
  "  parameter Real C[q, n] = zeros(q, n);%s\n"
  "  parameter Real D[q, p] = zeros(q, p);%s\n"
  "  parameter Real Cz[nz, n] = zeros(nz, n);%s\n"
  "  parameter Real Dz[nz, p] = zeros(nz, p);%s\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[p];\n"
  "  output Real y[q];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'z_$cse1' = z[1];\n""  Real 'z_$cse2' = z[2];\n""  Real 'z_$cse3' = z[3];\n""  Real 'z_$cse4' = z[4];\n""  Real 'z_$cse5' = z[5];\n""  Real 'z_Heater1.heatAdd' = z[6];\n""  Real 'z_Heater1.inVapPhasMolFrac' = z[7];\n""  Real 'z_Heater1.outP' = z[8];\n""  Real 'z_Heater1.outT' = z[9];\n""  Real 'z_Heater1.outVapPhasMolFrac' = z[10];\n""  Real 'z_Heater1.tempInc' = z[11];\n""  Real 'z_MatStm1.K[1]' = z[12];\n""  Real 'z_MatStm1.K[2]' = z[13];\n""  Real 'z_MatStm1.MW[1]' = z[14];\n""  Real 'z_MatStm1.MW[2]' = z[15];\n""  Real 'z_MatStm1.MW[3]' = z[16];\n""  Real 'z_MatStm1.Pbubl' = z[17];\n""  Real 'z_MatStm1.Pdew' = z[18];\n""  Real 'z_MatStm1.Psat[1]' = z[19];\n""  Real 'z_MatStm1.Psat[2]' = z[20];\n""  Real 'z_MatStm1.compMasFlo[1,1]' = z[21];\n""  Real 'z_MatStm1.compMasFlo[1,2]' = z[22];\n""  Real 'z_MatStm1.compMasFlo[2,1]' = z[23];\n""  Real 'z_MatStm1.compMasFlo[2,2]' = z[24];\n""  Real 'z_MatStm1.compMasFlo[3,1]' = z[25];\n""  Real 'z_MatStm1.compMasFlo[3,2]' = z[26];\n""  Real 'z_MatStm1.compMasFrac[1,1]' = z[27];\n""  Real 'z_MatStm1.compMasFrac[1,2]' = z[28];\n""  Real 'z_MatStm1.compMasFrac[2,1]' = z[29];\n""  Real 'z_MatStm1.compMasFrac[2,2]' = z[30];\n""  Real 'z_MatStm1.compMasFrac[3,1]' = z[31];\n""  Real 'z_MatStm1.compMasFrac[3,2]' = z[32];\n""  Real 'z_MatStm1.compMolEnth[1,1]' = z[33];\n""  Real 'z_MatStm1.compMolEnth[1,2]' = z[34];\n""  Real 'z_MatStm1.compMolEnth[2,1]' = z[35];\n""  Real 'z_MatStm1.compMolEnth[2,2]' = z[36];\n""  Real 'z_MatStm1.compMolEnth[3,1]' = z[37];\n""  Real 'z_MatStm1.compMolEnth[3,2]' = z[38];\n""  Real 'z_MatStm1.compMolEntr[1,1]' = z[39];\n""  Real 'z_MatStm1.compMolEntr[1,2]' = z[40];\n""  Real 'z_MatStm1.compMolEntr[2,1]' = z[41];\n""  Real 'z_MatStm1.compMolEntr[2,2]' = z[42];\n""  Real 'z_MatStm1.compMolEntr[3,1]' = z[43];\n""  Real 'z_MatStm1.compMolEntr[3,2]' = z[44];\n""  Real 'z_MatStm1.compMolFlo[1,1]' = z[45];\n""  Real 'z_MatStm1.compMolFlo[1,2]' = z[46];\n""  Real 'z_MatStm1.compMolFlo[2,1]' = z[47];\n""  Real 'z_MatStm1.compMolFlo[2,2]' = z[48];\n""  Real 'z_MatStm1.compMolFlo[3,1]' = z[49];\n""  Real 'z_MatStm1.compMolFlo[3,2]' = z[50];\n""  Real 'z_MatStm1.compMolFrac[1,1]' = z[51];\n""  Real 'z_MatStm1.compMolFrac[1,2]' = z[52];\n""  Real 'z_MatStm1.compMolFrac[2,1]' = z[53];\n""  Real 'z_MatStm1.compMolFrac[2,2]' = z[54];\n""  Real 'z_MatStm1.compMolFrac[3,1]' = z[55];\n""  Real 'z_MatStm1.compMolFrac[3,2]' = z[56];\n""  Real 'z_MatStm1.compMolSpHeat[1,1]' = z[57];\n""  Real 'z_MatStm1.compMolSpHeat[1,2]' = z[58];\n""  Real 'z_MatStm1.compMolSpHeat[2,1]' = z[59];\n""  Real 'z_MatStm1.compMolSpHeat[2,2]' = z[60];\n""  Real 'z_MatStm1.compMolSpHeat[3,1]' = z[61];\n""  Real 'z_MatStm1.compMolSpHeat[3,2]' = z[62];\n""  Real 'z_MatStm1.gamma[1]' = z[63];\n""  Real 'z_MatStm1.gamma[2]' = z[64];\n""  Real 'z_MatStm1.gammaBubl[1]' = z[65];\n""  Real 'z_MatStm1.gammaBubl[2]' = z[66];\n""  Real 'z_MatStm1.gammaDew[1]' = z[67];\n""  Real 'z_MatStm1.gammaDew[2]' = z[68];\n""  Real 'z_MatStm1.liqPhasMasFrac' = z[69];\n""  Real 'z_MatStm1.liqPhasMolFrac' = z[70];\n""  Real 'z_MatStm1.liqfugcoeff_bubl[1]' = z[71];\n""  Real 'z_MatStm1.liqfugcoeff_bubl[2]' = z[72];\n""  Real 'z_MatStm1.phasMolEnth[1]' = z[73];\n""  Real 'z_MatStm1.phasMolEnth[2]' = z[74];\n""  Real 'z_MatStm1.phasMolEnth[3]' = z[75];\n""  Real 'z_MatStm1.phasMolEntr[1]' = z[76];\n""  Real 'z_MatStm1.phasMolEntr[2]' = z[77];\n""  Real 'z_MatStm1.phasMolEntr[3]' = z[78];\n""  Real 'z_MatStm1.phasMolSpHeat[1]' = z[79];\n""  Real 'z_MatStm1.phasMolSpHeat[2]' = z[80];\n""  Real 'z_MatStm1.phasMolSpHeat[3]' = z[81];\n""  Real 'z_MatStm1.resMolEnth[1]' = z[82];\n""  Real 'z_MatStm1.resMolEnth[2]' = z[83];\n""  Real 'z_MatStm1.resMolEnth[3]' = z[84];\n""  Real 'z_MatStm1.resMolEntr[1]' = z[85];\n""  Real 'z_MatStm1.resMolEntr[2]' = z[86];\n""  Real 'z_MatStm1.resMolEntr[3]' = z[87];\n""  Real 'z_MatStm1.resMolSpHeat[1]' = z[88];\n""  Real 'z_MatStm1.resMolSpHeat[2]' = z[89];\n""  Real 'z_MatStm1.resMolSpHeat[3]' = z[90];\n""  Real 'z_MatStm1.totMasFlo[1]' = z[91];\n""  Real 'z_MatStm1.totMasFlo[2]' = z[92];\n""  Real 'z_MatStm1.totMasFlo[3]' = z[93];\n""  Real 'z_MatStm1.totMolFlo[2]' = z[94];\n""  Real 'z_MatStm1.totMolFlo[3]' = z[95];\n""  Real 'z_MatStm1.vapPhasMasFrac' = z[96];\n""  Real 'z_MatStm1.vapfugcoeff_dew[1]' = z[97];\n""  Real 'z_MatStm1.vapfugcoeff_dew[2]' = z[98];\n""  Real 'z_MatStm4.K[1]' = z[99];\n""  Real 'z_MatStm4.K[2]' = z[100];\n""  Real 'z_MatStm4.MW[1]' = z[101];\n""  Real 'z_MatStm4.MW[2]' = z[102];\n""  Real 'z_MatStm4.MW[3]' = z[103];\n""  Real 'z_MatStm4.P' = z[104];\n""  Real 'z_MatStm4.Pbubl' = z[105];\n""  Real 'z_MatStm4.Pdew' = z[106];\n""  Real 'z_MatStm4.Psat[1]' = z[107];\n""  Real 'z_MatStm4.Psat[2]' = z[108];\n""  Real 'z_MatStm4.T' = z[109];\n""  Real 'z_MatStm4.compMasFlo[1,1]' = z[110];\n""  Real 'z_MatStm4.compMasFlo[1,2]' = z[111];\n""  Real 'z_MatStm4.compMasFlo[2,1]' = z[112];\n""  Real 'z_MatStm4.compMasFlo[2,2]' = z[113];\n""  Real 'z_MatStm4.compMasFlo[3,1]' = z[114];\n""  Real 'z_MatStm4.compMasFlo[3,2]' = z[115];\n""  Real 'z_MatStm4.compMasFrac[1,1]' = z[116];\n""  Real 'z_MatStm4.compMasFrac[1,2]' = z[117];\n""  Real 'z_MatStm4.compMasFrac[2,1]' = z[118];\n""  Real 'z_MatStm4.compMasFrac[2,2]' = z[119];\n""  Real 'z_MatStm4.compMasFrac[3,1]' = z[120];\n""  Real 'z_MatStm4.compMasFrac[3,2]' = z[121];\n""  Real 'z_MatStm4.compMolEnth[1,1]' = z[122];\n""  Real 'z_MatStm4.compMolEnth[1,2]' = z[123];\n""  Real 'z_MatStm4.compMolEnth[2,1]' = z[124];\n""  Real 'z_MatStm4.compMolEnth[2,2]' = z[125];\n""  Real 'z_MatStm4.compMolEnth[3,1]' = z[126];\n""  Real 'z_MatStm4.compMolEnth[3,2]' = z[127];\n""  Real 'z_MatStm4.compMolEntr[1,1]' = z[128];\n""  Real 'z_MatStm4.compMolEntr[1,2]' = z[129];\n""  Real 'z_MatStm4.compMolEntr[2,1]' = z[130];\n""  Real 'z_MatStm4.compMolEntr[2,2]' = z[131];\n""  Real 'z_MatStm4.compMolEntr[3,1]' = z[132];\n""  Real 'z_MatStm4.compMolEntr[3,2]' = z[133];\n""  Real 'z_MatStm4.compMolFlo[1,1]' = z[134];\n""  Real 'z_MatStm4.compMolFlo[1,2]' = z[135];\n""  Real 'z_MatStm4.compMolFlo[2,1]' = z[136];\n""  Real 'z_MatStm4.compMolFlo[2,2]' = z[137];\n""  Real 'z_MatStm4.compMolFlo[3,1]' = z[138];\n""  Real 'z_MatStm4.compMolFlo[3,2]' = z[139];\n""  Real 'z_MatStm4.compMolFrac[1,1]' = z[140];\n""  Real 'z_MatStm4.compMolFrac[1,2]' = z[141];\n""  Real 'z_MatStm4.compMolFrac[2,1]' = z[142];\n""  Real 'z_MatStm4.compMolFrac[2,2]' = z[143];\n""  Real 'z_MatStm4.compMolFrac[3,1]' = z[144];\n""  Real 'z_MatStm4.compMolFrac[3,2]' = z[145];\n""  Real 'z_MatStm4.compMolSpHeat[1,1]' = z[146];\n""  Real 'z_MatStm4.compMolSpHeat[1,2]' = z[147];\n""  Real 'z_MatStm4.compMolSpHeat[2,1]' = z[148];\n""  Real 'z_MatStm4.compMolSpHeat[2,2]' = z[149];\n""  Real 'z_MatStm4.compMolSpHeat[3,1]' = z[150];\n""  Real 'z_MatStm4.compMolSpHeat[3,2]' = z[151];\n""  Real 'z_MatStm4.gamma[1]' = z[152];\n""  Real 'z_MatStm4.gamma[2]' = z[153];\n""  Real 'z_MatStm4.gammaBubl[1]' = z[154];\n""  Real 'z_MatStm4.gammaBubl[2]' = z[155];\n""  Real 'z_MatStm4.gammaDew[1]' = z[156];\n""  Real 'z_MatStm4.gammaDew[2]' = z[157];\n""  Real 'z_MatStm4.liqPhasMasFrac' = z[158];\n""  Real 'z_MatStm4.liqPhasMolFrac' = z[159];\n""  Real 'z_MatStm4.liqfugcoeff_bubl[1]' = z[160];\n""  Real 'z_MatStm4.liqfugcoeff_bubl[2]' = z[161];\n""  Real 'z_MatStm4.phasMolEnth[1]' = z[162];\n""  Real 'z_MatStm4.phasMolEnth[2]' = z[163];\n""  Real 'z_MatStm4.phasMolEnth[3]' = z[164];\n""  Real 'z_MatStm4.phasMolEntr[1]' = z[165];\n""  Real 'z_MatStm4.phasMolEntr[2]' = z[166];\n""  Real 'z_MatStm4.phasMolEntr[3]' = z[167];\n""  Real 'z_MatStm4.phasMolSpHeat[1]' = z[168];\n""  Real 'z_MatStm4.phasMolSpHeat[2]' = z[169];\n""  Real 'z_MatStm4.phasMolSpHeat[3]' = z[170];\n""  Real 'z_MatStm4.resMolEnth[1]' = z[171];\n""  Real 'z_MatStm4.resMolEnth[2]' = z[172];\n""  Real 'z_MatStm4.resMolEnth[3]' = z[173];\n""  Real 'z_MatStm4.resMolEntr[1]' = z[174];\n""  Real 'z_MatStm4.resMolEntr[2]' = z[175];\n""  Real 'z_MatStm4.resMolEntr[3]' = z[176];\n""  Real 'z_MatStm4.resMolSpHeat[1]' = z[177];\n""  Real 'z_MatStm4.resMolSpHeat[2]' = z[178];\n""  Real 'z_MatStm4.resMolSpHeat[3]' = z[179];\n""  Real 'z_MatStm4.totMasFlo[1]' = z[180];\n""  Real 'z_MatStm4.totMasFlo[2]' = z[181];\n""  Real 'z_MatStm4.totMasFlo[3]' = z[182];\n""  Real 'z_MatStm4.totMolFlo[1]' = z[183];\n""  Real 'z_MatStm4.totMolFlo[2]' = z[184];\n""  Real 'z_MatStm4.totMolFlo[3]' = z[185];\n""  Real 'z_MatStm4.vapPhasMasFrac' = z[186];\n""  Real 'z_MatStm4.vapfugcoeff_dew[1]' = z[187];\n""  Real 'z_MatStm4.vapfugcoeff_dew[2]' = z[188];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_heater1;\n";
}
#if defined(__cplusplus)
}
#endif

