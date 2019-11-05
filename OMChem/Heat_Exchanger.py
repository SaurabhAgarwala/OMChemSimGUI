from OMChem.EngStm import EngStm
class Heat_Exchanger():
    def __init__(self,name='Heat_Exchanger', heatLoss = None, deltap_hot = None, deltap_cold = None, mode = '',calc_method = ''):
        self.heatLoss = heatLoss
        self.deltap_hot = deltap_hot
        self.deltap_cold = deltap_cold
        self.mode = mode
        self.calc_method = calc_method
        self.name = name
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = None
        self.OutputStms = None
        self.EngStms = EngStm(name='EngStm'+name)
        self.type = 'Heat_Exchanger'
        self.modeVal = None


    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms

    def modesList(self):
        return ["hotFlOutT","coldFlOutT","fOutT","fOutT-NTU","allParamsEstm"]

    def paramgetter(self,mode="hotFlOutT"):
        self.mode = mode
        dict = {"heatLoss":None,"deltap_hot":None,"deltap_cold":None,"calc_method":None,self.mode:None}
        return dict
        
    def paramsetter(self,dict):
        
        self.heatLoss = dict['heatLoss']
        self.deltap_hot = dict['deltap_hot']
        self.deltap_cold = dict['deltap_cold']
        self.modeVal = dict[self.mode]
        self.calc_method = dict['calc_method']

    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        comp_count = len(addedcomp)
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStms.name+';\n'
        self.OM_data_init = self.OM_data_init + (
        "Simulator.Unit_Operations.Heat_Exchanger " + self.name + "(NOC = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (",comp = {")
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("},")
        self.OM_data_init = self.OM_data_init + 'Heat_Loss = ' + str(self.heatLoss) +','
        self.OM_data_init = self.OM_data_init + 'deltap_hot = ' + str(self.deltap_hot) +','
        self.OM_data_init = self.OM_data_init + 'deltap_cold = ' + str(self.deltap_cold) +','
        self.OM_data_init = self.OM_data_init + 'Calculation_Method = ' + str(self.calc_method) + ');\n'
        return self.OM_data_init

    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        # self.OM_data_eqn = self.name + '.pressDrop = ' + str(self.PressDrop) + ';\n'
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.InputStms[0].name + '.outlet,' +  self.name + '.inlet' + ');\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.outlet,' + self.OutputStms[0].name + '.inlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.EngStms.name + '.outlet,' + self.name + '.energy);\n')

        return self.OM_data_eqn
