/* Linearization */
#include "Flowsheet_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *Flowsheet_linear_model_frame()
{
  return "model linear_Flowsheet\n  parameter Integer n = 0 \"number of states\";\n  parameter Integer p = 0 \"number of inputs\";\n  parameter Integer q = 0 \"number of outputs\";\n"
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
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_Flowsheet;\n";
}
const char *Flowsheet_linear_model_datarecovery_frame()
{
  return "model linear_Flowsheet\n  parameter Integer n = 0 \"number of states\";\n  parameter Integer p = 0 \"number of inputs\";\n  parameter Integer q = 0 \"number of outputs\";\n  parameter Integer nz = 129 \"data recovery variables\";\n"
  "\n"
  "  parameter Real x0[0] = %s;\n"
  "  parameter Real u0[0] = %s;\n"
  "  parameter Real z0[129] = %s;\n"
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
  "  Real 'z_$cse1' = z[1];\n""  Real 'z_$cse2' = z[2];\n""  Real 'z_Heater1.heatAdd' = z[3];\n""  Real 'z_Heater1.inVapPhasMolFrac' = z[4];\n""  Real 'z_Heater1.outP' = z[5];\n""  Real 'z_Heater1.outT' = z[6];\n""  Real 'z_Heater1.outVapPhasMolFrac' = z[7];\n""  Real 'z_Heater1.tempInc' = z[8];\n""  Real 'z_MatStm1.K[1]' = z[9];\n""  Real 'z_MatStm1.MW[1]' = z[10];\n""  Real 'z_MatStm1.MW[2]' = z[11];\n""  Real 'z_MatStm1.MW[3]' = z[12];\n""  Real 'z_MatStm1.Pbubl' = z[13];\n""  Real 'z_MatStm1.Pdew' = z[14];\n""  Real 'z_MatStm1.Psat[1]' = z[15];\n""  Real 'z_MatStm1.compMasFlo[1,1]' = z[16];\n""  Real 'z_MatStm1.compMasFlo[2,1]' = z[17];\n""  Real 'z_MatStm1.compMasFlo[3,1]' = z[18];\n""  Real 'z_MatStm1.compMasFrac[1,1]' = z[19];\n""  Real 'z_MatStm1.compMasFrac[2,1]' = z[20];\n""  Real 'z_MatStm1.compMasFrac[3,1]' = z[21];\n""  Real 'z_MatStm1.compMolEnth[1,1]' = z[22];\n""  Real 'z_MatStm1.compMolEnth[2,1]' = z[23];\n""  Real 'z_MatStm1.compMolEnth[3,1]' = z[24];\n""  Real 'z_MatStm1.compMolEntr[1,1]' = z[25];\n""  Real 'z_MatStm1.compMolEntr[2,1]' = z[26];\n""  Real 'z_MatStm1.compMolEntr[3,1]' = z[27];\n""  Real 'z_MatStm1.compMolFlo[1,1]' = z[28];\n""  Real 'z_MatStm1.compMolFlo[2,1]' = z[29];\n""  Real 'z_MatStm1.compMolFlo[3,1]' = z[30];\n""  Real 'z_MatStm1.compMolFrac[1,1]' = z[31];\n""  Real 'z_MatStm1.compMolFrac[2,1]' = z[32];\n""  Real 'z_MatStm1.compMolFrac[3,1]' = z[33];\n""  Real 'z_MatStm1.compMolSpHeat[1,1]' = z[34];\n""  Real 'z_MatStm1.compMolSpHeat[2,1]' = z[35];\n""  Real 'z_MatStm1.compMolSpHeat[3,1]' = z[36];\n""  Real 'z_MatStm1.gamma[1]' = z[37];\n""  Real 'z_MatStm1.gammaBubl[1]' = z[38];\n""  Real 'z_MatStm1.gammaDew[1]' = z[39];\n""  Real 'z_MatStm1.liqPhasMasFrac' = z[40];\n""  Real 'z_MatStm1.liqPhasMolFrac' = z[41];\n""  Real 'z_MatStm1.liqfugcoeff_bubl[1]' = z[42];\n""  Real 'z_MatStm1.phasMolEnth[1]' = z[43];\n""  Real 'z_MatStm1.phasMolEnth[2]' = z[44];\n""  Real 'z_MatStm1.phasMolEnth[3]' = z[45];\n""  Real 'z_MatStm1.phasMolEntr[1]' = z[46];\n""  Real 'z_MatStm1.phasMolEntr[2]' = z[47];\n""  Real 'z_MatStm1.phasMolEntr[3]' = z[48];\n""  Real 'z_MatStm1.phasMolSpHeat[1]' = z[49];\n""  Real 'z_MatStm1.phasMolSpHeat[2]' = z[50];\n""  Real 'z_MatStm1.phasMolSpHeat[3]' = z[51];\n""  Real 'z_MatStm1.resMolEnth[1]' = z[52];\n""  Real 'z_MatStm1.resMolEnth[2]' = z[53];\n""  Real 'z_MatStm1.resMolEnth[3]' = z[54];\n""  Real 'z_MatStm1.resMolEntr[1]' = z[55];\n""  Real 'z_MatStm1.resMolEntr[2]' = z[56];\n""  Real 'z_MatStm1.resMolEntr[3]' = z[57];\n""  Real 'z_MatStm1.resMolSpHeat[1]' = z[58];\n""  Real 'z_MatStm1.resMolSpHeat[2]' = z[59];\n""  Real 'z_MatStm1.resMolSpHeat[3]' = z[60];\n""  Real 'z_MatStm1.totMasFlo[1]' = z[61];\n""  Real 'z_MatStm1.totMasFlo[2]' = z[62];\n""  Real 'z_MatStm1.totMasFlo[3]' = z[63];\n""  Real 'z_MatStm1.totMolFlo[2]' = z[64];\n""  Real 'z_MatStm1.totMolFlo[3]' = z[65];\n""  Real 'z_MatStm1.vapPhasMasFrac' = z[66];\n""  Real 'z_MatStm1.vapfugcoeff_dew[1]' = z[67];\n""  Real 'z_MatStm2.K[1]' = z[68];\n""  Real 'z_MatStm2.MW[1]' = z[69];\n""  Real 'z_MatStm2.MW[2]' = z[70];\n""  Real 'z_MatStm2.MW[3]' = z[71];\n""  Real 'z_MatStm2.P' = z[72];\n""  Real 'z_MatStm2.Pbubl' = z[73];\n""  Real 'z_MatStm2.Pdew' = z[74];\n""  Real 'z_MatStm2.Psat[1]' = z[75];\n""  Real 'z_MatStm2.T' = z[76];\n""  Real 'z_MatStm2.compMasFlo[1,1]' = z[77];\n""  Real 'z_MatStm2.compMasFlo[2,1]' = z[78];\n""  Real 'z_MatStm2.compMasFlo[3,1]' = z[79];\n""  Real 'z_MatStm2.compMasFrac[1,1]' = z[80];\n""  Real 'z_MatStm2.compMasFrac[2,1]' = z[81];\n""  Real 'z_MatStm2.compMasFrac[3,1]' = z[82];\n""  Real 'z_MatStm2.compMolEnth[1,1]' = z[83];\n""  Real 'z_MatStm2.compMolEnth[2,1]' = z[84];\n""  Real 'z_MatStm2.compMolEnth[3,1]' = z[85];\n""  Real 'z_MatStm2.compMolEntr[1,1]' = z[86];\n""  Real 'z_MatStm2.compMolEntr[2,1]' = z[87];\n""  Real 'z_MatStm2.compMolEntr[3,1]' = z[88];\n""  Real 'z_MatStm2.compMolFlo[1,1]' = z[89];\n""  Real 'z_MatStm2.compMolFlo[2,1]' = z[90];\n""  Real 'z_MatStm2.compMolFlo[3,1]' = z[91];\n""  Real 'z_MatStm2.compMolFrac[1,1]' = z[92];\n""  Real 'z_MatStm2.compMolFrac[2,1]' = z[93];\n""  Real 'z_MatStm2.compMolFrac[3,1]' = z[94];\n""  Real 'z_MatStm2.compMolSpHeat[1,1]' = z[95];\n""  Real 'z_MatStm2.compMolSpHeat[2,1]' = z[96];\n""  Real 'z_MatStm2.compMolSpHeat[3,1]' = z[97];\n""  Real 'z_MatStm2.gamma[1]' = z[98];\n""  Real 'z_MatStm2.gammaBubl[1]' = z[99];\n""  Real 'z_MatStm2.gammaDew[1]' = z[100];\n""  Real 'z_MatStm2.liqPhasMasFrac' = z[101];\n""  Real 'z_MatStm2.liqPhasMolFrac' = z[102];\n""  Real 'z_MatStm2.liqfugcoeff_bubl[1]' = z[103];\n""  Real 'z_MatStm2.phasMolEnth[1]' = z[104];\n""  Real 'z_MatStm2.phasMolEnth[2]' = z[105];\n""  Real 'z_MatStm2.phasMolEnth[3]' = z[106];\n""  Real 'z_MatStm2.phasMolEntr[1]' = z[107];\n""  Real 'z_MatStm2.phasMolEntr[2]' = z[108];\n""  Real 'z_MatStm2.phasMolEntr[3]' = z[109];\n""  Real 'z_MatStm2.phasMolSpHeat[1]' = z[110];\n""  Real 'z_MatStm2.phasMolSpHeat[2]' = z[111];\n""  Real 'z_MatStm2.phasMolSpHeat[3]' = z[112];\n""  Real 'z_MatStm2.resMolEnth[1]' = z[113];\n""  Real 'z_MatStm2.resMolEnth[2]' = z[114];\n""  Real 'z_MatStm2.resMolEnth[3]' = z[115];\n""  Real 'z_MatStm2.resMolEntr[1]' = z[116];\n""  Real 'z_MatStm2.resMolEntr[2]' = z[117];\n""  Real 'z_MatStm2.resMolEntr[3]' = z[118];\n""  Real 'z_MatStm2.resMolSpHeat[1]' = z[119];\n""  Real 'z_MatStm2.resMolSpHeat[2]' = z[120];\n""  Real 'z_MatStm2.resMolSpHeat[3]' = z[121];\n""  Real 'z_MatStm2.totMasFlo[1]' = z[122];\n""  Real 'z_MatStm2.totMasFlo[2]' = z[123];\n""  Real 'z_MatStm2.totMasFlo[3]' = z[124];\n""  Real 'z_MatStm2.totMolFlo[1]' = z[125];\n""  Real 'z_MatStm2.totMolFlo[2]' = z[126];\n""  Real 'z_MatStm2.totMolFlo[3]' = z[127];\n""  Real 'z_MatStm2.vapPhasMasFrac' = z[128];\n""  Real 'z_MatStm2.vapfugcoeff_dew[1]' = z[129];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_Flowsheet;\n";
}
#if defined(__cplusplus)
}
#endif

