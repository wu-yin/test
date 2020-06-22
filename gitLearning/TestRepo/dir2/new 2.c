从 KParameter 中获取 kparam.getWaveSampleRate() ->
allParam->getWaveSampleRate(_myType); ->		// enum KParamType _myType;
return _waveSampleRate[kpType]; ->				// QMap<KParamType, float> _waveSampleRate;
												// enum KParamType kpType;
// 是从 _waveSampleRate[] 中获取的采样率
// 但是 采样率 是如何设置进去的？
DeviceParameters::_initEcg()	┐
DeviceParameters::_initSpo2()	├─>
DeviceParameters::_initResp()	│
DeviceParameters::_initNibp()	┘
void AllParameter::setWaveSampleRate(KParamType kpType, float sampleRate) {
	_waveSampleRate.insert(kpType, sampleRate);
}



MicSendProtocol::setActiveParam() ->
kparam.getWaveBytes(); ->					// KParameter kparam
return allParam->getWaveBytes(_myType);
return _waveBytes[getParameter(kpType)];

// 是如何设置进 _waveBytes[] 的？
DeviceParameters::_initEcg()	┐
DeviceParameters::_initSpo2()	├─>
DeviceParameters::_initResp()	┘
allParam->setWaveBytes(SPO2, 2);



//----------------------------------
// 组装波形数据
Fy0803Device::_handleEcgWavePkg(int len) {
	......
	wavePublisher->add(ECG_I, wave2 | mask);
	......
}

bool Fy0803Device::_handleSpo2WavePkg(int len) {
	......
	wavePublisher->add(SPO2_WAVE, data[0] | mask | (stickValue << 11));
	......
}





typedef enum {
	CHPKGID_UNKNOWN = 0x0,

	CHPKGID_SYS_RESET = 0x01,        // 系统复位信息
	CHPKGID_SYS_SELF_TEST = 0x02,    // 系统自检结果
	CHPKGID_CMD_RESPOND = 0x03,      // 命令应答

	CHPKGID_ECGWAVE_1 = 0x11,        // 第1道心电波形		0d17
	CHPKGID_ECGWAVE_2 = 0x12,        // 第2道心电波形		0d18
	CHPKGID_ECGWAVE_3 = 0x13,        // 第3道心电波形		0d19
	CHPKGID_ECGWAVE_4 = 0x14,        // 第4道心电波形		0d20
	CHPKGID_ECGWAVE_5 = 0x15,        // 第5道心电波形		0d21
	CHPKGID_ECGWAVE_6 = 0x16,        // 第6道心电波形		0d22
	CHPKGID_ECGWAVE_7 = 0x17,        // 第7道心电波形		0d23
	CHPKGID_ECGWAVE_8 = 0x18,        // 第8道心电波形		0d24
	CHPKGID_ECGLEAD = 0x19,          // 心电导联信息		0d25
	CHPKGID_ECGHR = 0x1A,            // 心率				0d26

	CHPKGID_SPO2WAVE = 0x20,         // SPO2波形			0d32
	CHPKGID_SPO2SENSOR_ST = 0x21,    // SPO2探头状态		0d33
	CHPKGID_SPO2_PR = 0x22,          // SPO2趋势值/脉率		0d34

	CHPKGID_NIBP_END = 0x30,         // NIBP测量结束
	CHPKGID_NIBP_RESULT = 0x31,      // NIBP测量值
	CHPKGID_NIBP_PR = 0x32,          // NIBP测量脉率
	CHPKGID_NIBP_ST = 0x33,          // NIBP状态
	CHPKGID_NIBP_CUFF = 0x34,        // NIBP袖带压
} ChPkgId;



public class KParamType {
    public static final int ECG = 0;
    public static final int ECG_I = 1;
    public static final int ECG_II = 2;
    public static final int ECG_III = 3;
    public static final int ECG_AVR = 4;
    public static final int ECG_AVL = 5;
    public static final int ECG_AVF = 6;
    public static final int ECG_V1 = 7;
    public static final int ECG_V2 = 8;
    public static final int ECG_V3 = 9;
    public static final int ECG_V4 = 10;
    public static final int ECG_V5 = 11;
    public static final int ECG_V6 = 12;
    //心电原始数据子参数
    public static final int ECG_RAW_I = 0x17;
    public static final int ECG_RAW_II = 0x18;
    public static final int ECG_RAW_III = 0x19;
    public static final int ECG_RAW_V1 = 0x1A;
    public static final int ECG_RAW_V2 = 0x1B;
    public static final int ECG_RAW_V3 = 0x1C;
    public static final int ECG_RAW_V4 = 0x1D;
    public static final int ECG_RAW_V5 = 0x1E;
    public static final int ECG_RAW_V6 = 0x1F;

    // ECG趋势子参数
    public static final int ECG_HR = 14;
    public static final int ECG_PVC = 15;
    public static final int ECG_ST = 18;
    public static final int ECG_FALL_OFF = 504; //TODO 心电脱落(为啥是一样的？)
    public static final int ECG_NORMAL_CONNECTION = 504; //心电正常连接
    public static final short START_ECG_DIAGNOSE = (short) 0X15; //心电启动测量
    public static final int ECG_CONNECTION_STATUS = 0x10; //心电连接状态码标示
    public static final int ECG_ABNORMAL = 0x11; //心率失常标示
    //计算导联1导联为 0 ，2导联为 1 自动为10
    public static final int COUNT_ECG_I = 0;
    public static final int COUNT_ECG_II = 1;
    public static final int COUNT_ECG = 10;

    // resp趋势子参数
    public static final int RESP_RR = 102;

    // spo2趋势子参数
    public static final int SPO2_WAVE = 201;
    public static final int SPO2_TREND = 202;
    public static final int SPO2_PR = 203;
    //spo2原始数据子参数
    public static final int SPO2_RED = 204;
    public static final int SPO2_IRD = 205;
    public static final int SPO2_ENV = 206;


    // temp趋势子参数
    public static final int TEMP_T1 = 301;
    public static final int TEMP_T2 = 302;
    public static final int TEMP_TD = 303;

    // irTemp趋势子参数
    public static final int IRTEMP_TREND = 401; //红外耳温

    // nibp趋势子参数
    public static final int NIBP_SYS = 501; //收缩压
    public static final int NIBP_DIA = 502; //舒张压
    public static final int NIBP_MAP = 503;
    public static final int NIBP_PR = 504;
    //血压原始数据子参数
    public static final int NIBP_RAW = 505;

    // bloodGlu趋势子参数
    public static final int BLOODGLU_BEFORE_MEAL = 901;
    public static final int BLOODGLU_AFTER_MEAL = 902;

    // urineRt趋势子参数
    public static final int URINERT_LEU = 1201;
    public static final int URINERT_NIT = 1202;
    public static final int URINERT_UBG = 1203;
    public static final int URINERT_PRO = 1204;
    public static final int URINERT_PH = 1205;
    public static final int URINERT_BLD = 1206;
    public static final int URINERT_SG = 1207;
    public static final int URINERT_BIL = 1208;
    public static final int URINERT_KET = 1209;
    public static final int URINERT_GLU = 1210;
    public static final int URINERT_VC = 1211; //维生素c
    public static final int URINERT_ALB = 1212; //微量白蛋白
    public static final int URINERT_ASC = 1213; //抗坏血酸
    public static final int URINERT_CRE = 1214;
    public static final int URINERT_CA = 1215;

    //bloodWbc趋势子参数
    public static final int BLOOD_WBC = 1401;

    public static final int BLOOD_HGB = 1402;
    public static final int BLOOD_HCT = 1403;

    //尿酸(百捷三合一)
    public static final int URICACID_TREND = 1001;
    //总胆固醇(百捷三合一)
    public static final int CHOLESTEROL_TREND = 1101;
    //血脂四项
    public static final int BLOOD_FAT_CHO = 1501;
    public static final int BLOOD_FAT_TRIG = 1502;
    public static final int BLOOD_FAT_HDL = 1503;
    public static final int BLOOD_FAT_LDL = 1504;

    public static final int WEIGHT = 2001;
    public static final int HEIGHT = 2002;
    public static final int BMI = 2003;
    //糖化
    //糖化血红蛋白值-NGSP标准
    public static final int GHB_HBA1C_NGSP = 1601;
    //糖化血红蛋白值-IFCC标准
    public static final int GHB_HBA1C_IFCC = 1602;
    //平均血糖浓度
    public static final int GHB_EAG = 1603;

    public static final int URINE_AC = 1216; //A:C 艾康特有
}







































