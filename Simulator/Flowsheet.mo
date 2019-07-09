model Flowsheet
parameter Simulator.Files.Chemsep_Database.Water Water; 
parameter Simulator.Files.Chemsep_Database.Ethanol Ethanol; 
Simulator.Unit_Operations.Mixer Mixer1(NOC = 2,comp = {Water, Ethanol},outPress = "Inlet_Average",NI=2);
Simulator.Unit_Operations.Splitter Splitter1(NOC = 2,comp = {Water, Ethanol},calcType = "Molar_Flow",NO=2);
model ms1
extends Simulator.Streams.Material_Stream;
extends Simulator.Files.Thermodynamic_Packages.Raoults_Law;
end ms1;
ms1 MatStm1(NOC = 2,comp = {Water, Ethanol});
model ms2
extends Simulator.Streams.Material_Stream;
extends Simulator.Files.Thermodynamic_Packages.Raoults_Law;
end ms2;
ms2 MatStm2(NOC = 2,comp = {Water, Ethanol});
model ms3
extends Simulator.Streams.Material_Stream;
extends Simulator.Files.Thermodynamic_Packages.Raoults_Law;
end ms3;
ms3 MatStm3(NOC = 2,comp = {Water, Ethanol});
model ms4
extends Simulator.Streams.Material_Stream;
extends Simulator.Files.Thermodynamic_Packages.Raoults_Law;
end ms4;
ms4 MatStm4(NOC = 2,comp = {Water, Ethanol});
model ms5
extends Simulator.Streams.Material_Stream;
extends Simulator.Files.Thermodynamic_Packages.Raoults_Law;
end ms5;
ms5 MatStm5(NOC = 2,comp = {Water, Ethanol});
equation
connect(MatStm3.outlet,Mixer1.inlet[1]);
connect(MatStm2.outlet,Mixer1.inlet[2]);
connect(Mixer1.outlet,MatStm1.inlet);
connect(MatStm5.inlet,Splitter1.outlet[1]);
connect(MatStm4.inlet,Splitter1.outlet[2]);
connect(Splitter1.inlet,MatStm1.outlet);
Splitter1.specVal ={50, 50};
MatStm2.P = 101325;
MatStm2.T = 310;
MatStm2.compMolFrac[1,:] = {0.4, 0.6};
MatStm2.totMolFlo[1] = 100;
MatStm3.P = 101325;
MatStm3.T = 310;
MatStm3.compMolFrac[1,:] = {0.5, 0.5};
MatStm3.totMolFlo[1] = 100;
end Flowsheet;
