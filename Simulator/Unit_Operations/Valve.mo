within Simulator.Unit_Operations;

model Valve
  extends Simulator.Files.Icons.Valve;
  // This is generic valve model. For using this model we need to extend this model and incorporte ouput material stream since this model is not doing any flash calculations. Refer valve model in Test section for this.
  //====================================================================================
  Real inMolFlo(min = 0, start = 100) "inlet mixture molar flow rate", outMolFlo(min = 0, start = 100) "outlet mixture molar flow rate", inP(min = 0, start = 101325) "Inlet pressure", outP(min = 0, start = 101325) "Outlet pressure", pressDrop "Pressure drop", inT(min = 0, start = 273.15) "Inlet Temperature", outT(min = 0, start = 273.15) "Outlet Temperature", tempInc "Temperature Increase";
  Real inMixMolEnth "inlet mixture molar enthalpy", outMixMolEnth "outlet mixture molar enthalpy";
  Real inMixMolEntr "inlet mixture molar entropy", outMixMolEntr "outlet mixture molar entropy", mixMolFrac[NOC](each min = 0, each max = 1, each start = 1 / (NOC + 1)) "mixture mole fraction", inVapPhasMolFrac(min = 0, max = 1, start = 0.5) "Inlet vapor phase mole fraction", outVapPhasMolFrac(min = 0, max = 1, start = 0.5) "Outlet vapor phase mole fraction";
  //========================================================================================
  parameter Integer NOC = 3 "number of components";
  parameter Simulator.Files.Chemsep_Database.General_Properties comp[NOC];
  //========================================================================================
  Files.Connection.matConn inlet(connNOC = NOC) annotation(
    Placement(visible = true, transformation(origin = {-100, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-100, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Simulator.Files.Connection.matConn outlet(connNOC = NOC) annotation(
    Placement(visible = true, transformation(origin = {100, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {100, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //========================================================================================
equation
//connector equations
  inlet.P = inP;
  inlet.T = inT;
  inlet.mixMolFlo = inMolFlo;
  inlet.mixMolEnth = inMixMolEnth;
  inlet.mixMolEntr = inMixMolEntr;
  inlet.mixMolFrac[1, :] = mixMolFrac[:];
  inlet.vapPhasMolFrac = inVapPhasMolFrac;
  outlet.P = outP;
  outlet.T = outT;
  outlet.mixMolFlo = outMolFlo;
  outlet.mixMolEnth = outMixMolEnth;
  outlet.mixMolEntr = outMixMolEntr;
  outlet.mixMolFrac[1, :] = mixMolFrac[:];
  outlet.vapPhasMolFrac = outVapPhasMolFrac;
//=============================================================================================
  inMolFlo = outMolFlo;
//material balance
  inMixMolEnth = outMixMolEnth;
//energy balance
  inP - pressDrop = outP;
//pressure calculation
  inT + tempInc = outT;
//temperature calculation
end Valve;
