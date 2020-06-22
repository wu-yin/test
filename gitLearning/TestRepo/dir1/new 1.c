

TODO:

* MeasureEcgFragment::isEcgConnect
* EcgPresenterImpl::sendWave() { view.saveEcgWave(param, bytes) }

* EcgViewFor12::ecgPerCount

* MeasureQuicklyFragment::setLayoutVisiable() --> llUrt (R.id.ll_urt)
llUrt.setVisibility(View.VISIBLE);
llTemp.setVisibility(View.VISIBLE);
llBeneLayout.setVisibility(View.VISIBLE);
llGluLayout.setVisibility(View.VISIBLE);
llBeneLayout.setVisibility(View.GONE);



//=============================================================================
private byte[] ecgWaveII = new byte[CH_WAVE_SAMPLE_RATE];
private byte[] ecgWaveI = new byte[CH_WAVE_SAMPLE_RATE];
private byte[] ecgWaveV1 = new byte[CH_WAVE_SAMPLE_RATE];
private byte[] ecgWaveV2 = new byte[CH_WAVE_SAMPLE_RATE];
private byte[] ecgWaveV3 = new byte[CH_WAVE_SAMPLE_RATE];
private byte[] ecgWaveV4 = new byte[CH_WAVE_SAMPLE_RATE];
private byte[] ecgWaveV5 = new byte[CH_WAVE_SAMPLE_RATE];
private byte[] ecgWaveV6 = new byte[CH_WAVE_SAMPLE_RATE];

private int lastEcgIISerialNo = -1;
private int currentEcgIISerialNo = -1;

alignWithOneSecond(buff, cmdId, serialNo) {
	if(0x11 == cmdId) { // ECG 波形 II
		currentEcgIISerialNo = serialNo;
	}

}
















//=============================================================================
// 心电测量界面的“启动测量”按键使能
//=============================================================================
MeasureEcgFragment::btnStartMeasure.setEnabled(false)

//=============================================================================
// 快速测量界面显示数值
//=============================================================================
AIDLServer::handleMessage() ->
QuicklyPresenterImpl::sendTrend() ->
MeasureQuicklyFragment::setMeasureValue()

//=============================================================================
// SpO2测量失败后不会退出到待测量界面
//=============================================================================
// SpO2刷新界面风格的调用是：
Spo2PresenterImpl::onServiceConnected() --> {view.setSpo2Status()} -->
MeasureSpo2Fragment::refresh() --> {refreshGuide()}

// 其中最开始的 onServiceConnected() 是由探头状态来做后面响应驱动的，
// 而现在的调试状态是，下位机我一直发送的是探头状态OK
// 所以没法用探头状态异常来驱动后面的事件
// 以后用真实状态的时候再试下

//=============================================================================
// 红外体温CH协议格式
//=============================================================================
tempBuff[0] = 0xFF;
tempBuff[1] = 0x0A;		// Len
tempBuff[2] = 0x40;		// PkgId 0d64
tempBuff[3] = 0x00;		// SeriesNo
tempBuff[4] = 0x00;		// ChkSum
tempBuff[5] = 0x00;		// 单位：0-℃; 1-℉
tempBuff[6] = 0x00;		// 保留字节
tempBuff[7] = 0x00;		// 保留字节
tempBuff[8] =			// 整数位
tempBuff[9] =			// 小数位

//=============================================================================
// 血糖CH协议格式
//=============================================================================
buff[0] = 0xFF;
buff[1] = 0x0B;		// Len
buff[2] = 0x42;		// PkgId 0d66
buff[3] = 0x00;		// SeriesNo
buff[4] = 0x00;		// ChkSum
buff[5] = 0x00;		// 保留字节 机器型号、数据类型、校正码、单位
buff[6] = 0x00;		// 保留字节
buff[7] = 0x00;		// 保留字节
buff[8] = 0x00;		// 保留字节
buff[9] = 0x06;
buff[10] = 0x00;


//=============================================================================
// 尿常规CH协议格式
//=============================================================================
tempBuff[0] = 0xFF;
tempBuff[1] = 0x;		// Len
tempBuff[2] = 0x41;		// PkgId 0d65
tempBuff[3] = 0x00;		// SeriesNo
tempBuff[4] = 0x00;		// ChkSum
tempBuff[] =
tempBuff[] =
tempBuff[] =
tempBuff[] =
tempBuff[] =
tempBuff[] =
tempBuff[] =
tempBuff[] =
tempBuff[] =
tempBuff[] =

    public static final int URINERT_LEU = 1201;		// 白细胞 +-
    public static final int URINERT_NIT = 1202;		// 亚硝酸盐
    public static final int URINERT_UBG = 1203;		// 尿胆原 或者 URO
    public static final int URINERT_PRO = 1204;		// 蛋白
    public static final int URINERT_PH = 1205;		// PH值
    public static final int URINERT_BLD = 1206;		// 隐血 +-
    public static final int URINERT_SG = 1207;		// 比重
    public static final int URINERT_BIL = 1208;		// 胆红素
    public static final int URINERT_KET = 1209;		// 酮体
    public static final int URINERT_GLU = 1210;		// 葡萄糖
    public static final int URINERT_VC = 1211;		// 维生素C
    public static final int URINERT_ALB = 1212;		// 微量白蛋白
    public static final int URINERT_ASC = 1213;		// 维生素C		X
    public static final int URINERT_CRE = 1214;
    public static final int URINERT_CA = 1215;


KParamType.URINERT_LEU
KParamType.URINERT_NIT
KParamType.URINERT_UBG
KParamType.URINERT_PRO
KParamType.URINERT_PH
KParamType.URINERT_SG
KParamType.URINERT_BLD
KParamType.URINERT_KET
KParamType.URINERT_BIL
KParamType.URINERT_GLU
KParamType.URINERT_ASC
KParamType.URINERT_ALB 	// 14 项
KParamType.URINERT_CRE 	// 14 项
KParamType.URINERT_CA 	// 14 项

urtValueToString()
这个函数是用来把尿常规数据解析转换成字符串的


//=============================================================================
// 启动时崩溃输出 1
//=============================================================================
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onSearchComplete() = Device=9C:A5:25:A4:09:F1 Status=0
I/System.out: ---------------------------->发现服务
D/BluetoothGatt: onConfigureMTU() - Device=9C:A5:25:A4:09:F1 mtu=103 status=0
I/System.out: onMtuChanged-------------------->size:103
    onMtuChanged-------------------->设置成功
I/CrashReport: user log size:0
E/CrashReport: stack frame :9, has cause true
E/CrashReport: #++++++++++Record By Bugly++++++++++#
    # You can use Bugly(http:\\bugly.qq.com) to get more Crash Detail!
E/CrashReport: # PKG NAME: com.konsung.healthmeasure
E/CrashReport: # APP VER: 1.0.10
E/CrashReport: # SDK VER: 3.2.3-3.7.3
E/CrashReport: # LAUNCH TIME: 2020-06-13 22:37:19
E/CrashReport: # CRASH TYPE: JAVA_CRASH
E/CrashReport: # CRASH TIME: 2020-06-13 22:37:28
E/CrashReport: # CRASH PROCESS: com.konsung.healthmeasure
E/CrashReport: # CRASH THREAD: main
E/CrashReport: # REPORT ID: 0eee1b64-6f41-48c1-90dc-63a4ac5267c3
E/CrashReport: # CRASH DEVICE: P10S(N4H5) UNROOT
E/CrashReport: # RUNTIME AVAIL RAM:2442088448 ROM:24265383936 SD:24265383936
E/CrashReport: # RUNTIME TOTAL RAM:2961960960 ROM:27228336128 SD:27228336128
E/CrashReport: # CRASH STACK:
    java.lang.RuntimeException: Error receiving broadcast Intent { act=com.usr.bluetooth.le.ACTION_GATT_SERVICES_DISCOVERED flg=0x10 } in com.konsung.ui.activity.MeasureActivity$8@74039e6
        at android.app.LoadedApk$ReceiverDispatcher$Args.lambda$getRunnable$0(LoadedApk.java:1429)
        at android.app.-$$Lambda$LoadedApk$ReceiverDispatcher$Args$_BumDX2UKsnxLVrE6UJsJZkotuA.run(Unknown Source:2)
        at android.os.Handler.handleCallback(Handler.java:873)
        at android.os.Handler.dispatchMessage(Handler.java:99)
        at android.os.Looper.loop(Looper.java:193)
        at android.app.ActivityThread.main(ActivityThread.java:6865)
        at java.lang.reflect.Method.invoke(Native Method)
        at com.android.internal.os.RuntimeInit$MethodAndArgsCaller.run(RuntimeInit.java:504)
        at com.android.internal.os.ZygoteInit.main(ZygoteInit.java:858)
     Caused by: java.util.ConcurrentModificationException
        at java.util.ArrayList$Itr.next(ArrayList.java:860)
        at android.bluetooth.BluetoothGatt.getServices(BluetoothGatt.java:1029)
        at com.konsung.BlueToothLeService.BluetoothLeService.getSupportedGattServices(BluetoothLeService.java:962)
        at com.konsung.ui.activity.MeasureActivity$8.onReceive(MeasureActivity.java:781)
        at android.app.LoadedApk$ReceiverDispatcher$Args.lambda$getRunnable$0(LoadedApk.java:1419)
        at android.app.-$$Lambda$LoadedApk$ReceiverDispatcher$Args$_BumDX2UKsnxLVrE6UJsJZkotuA.run(Unknown Source:2) 
        at android.os.Handler.handleCallback(Handler.java:873) 
        at android.os.Handler.dispatchMessage(Handler.java:99) 
        at android.os.Looper.loop(Looper.java:193) 
        at android.app.ActivityThread.main(ActivityThread.java:6865) 
        at java.lang.reflect.Method.invoke(Native Method) 
        at com.android.internal.os.RuntimeInit$MethodAndArgsCaller.run(RuntimeInit.java:504) 
        at com.android.internal.os.ZygoteInit.main(ZygoteInit.java:858) 
    #++++++++++++++++++++++++++++++++++++++++++#


//=============================================================================
// 启动时崩溃输出 2
//=============================================================================
I/CrashReport: user log size:0
E/CrashReport: stack frame :9, has cause true
E/CrashReport: #++++++++++Record By Bugly++++++++++#
    # You can use Bugly(http:\\bugly.qq.com) to get more Crash Detail!
E/CrashReport: # PKG NAME: com.konsung.healthmeasure
E/CrashReport: # APP VER: 1.0.10
E/CrashReport: # SDK VER: 3.2.3-3.7.3
E/CrashReport: # LAUNCH TIME: 2020-06-13 22:39:04
E/CrashReport: # CRASH TYPE: JAVA_CRASH
E/CrashReport: # CRASH TIME: 2020-06-13 22:39:14
E/CrashReport: # CRASH PROCESS: com.konsung.healthmeasure
E/CrashReport: # CRASH THREAD: main
E/CrashReport: # REPORT ID: 2f185b5c-988a-49c5-813d-4c808bd2c916
E/CrashReport: # CRASH DEVICE: P10S(N4H5) UNROOT
E/CrashReport: # RUNTIME AVAIL RAM:2411253760 ROM:24265367552 SD:24265367552
E/CrashReport: # RUNTIME TOTAL RAM:2961960960 ROM:27228336128 SD:27228336128
    # CRASH STACK:
    java.lang.RuntimeException: Error receiving broadcast Intent { act=com.usr.bluetooth.le.ACTION_GATT_SERVICES_DISCOVERED flg=0x10 } in com.konsung.ui.activity.MeasureActivity$8@74039e6
        at android.app.LoadedApk$ReceiverDispatcher$Args.lambda$getRunnable$0(LoadedApk.java:1429)
        at android.app.-$$Lambda$LoadedApk$ReceiverDispatcher$Args$_BumDX2UKsnxLVrE6UJsJZkotuA.run(Unknown Source:2)
        at android.os.Handler.handleCallback(Handler.java:873)
        at android.os.Handler.dispatchMessage(Handler.java:99)
        at android.os.Looper.loop(Looper.java:193)
        at android.app.ActivityThread.main(ActivityThread.java:6865)
        at java.lang.reflect.Method.invoke(Native Method)
        at com.android.internal.os.RuntimeInit$MethodAndArgsCaller.run(RuntimeInit.java:504)
        at com.android.internal.os.ZygoteInit.main(ZygoteInit.java:858)
     Caused by: java.util.ConcurrentModificationException
        at java.util.ArrayList$Itr.next(ArrayList.java:860)
        at android.bluetooth.BluetoothGatt.getServices(BluetoothGatt.java:1029)
        at com.konsung.BlueToothLeService.BluetoothLeService.getSupportedGattServices(BluetoothLeService.java:962)
        at com.konsung.ui.activity.MeasureActivity$8.onReceive(MeasureActivity.java:781)
        at android.app.LoadedApk$ReceiverDispatcher$Args.lambda$getRunnable$0(LoadedApk.java:1419)
        at android.app.-$$Lambda$LoadedApk$ReceiverDispatcher$Args$_BumDX2UKsnxLVrE6UJsJZkotuA.run(Unknown Source:2) 
        at android.os.Handler.handleCallback(Handler.java:873) 
        at android.os.Handler.dispatchMessage(Handler.java:99) 
        at android.os.Looper.loop(Looper.java:193) 
        at android.app.ActivityThread.main(ActivityThread.java:6865) 
        at java.lang.reflect.Method.invoke(Native Method) 
        at com.android.internal.os.RuntimeInit$MethodAndArgsCaller.run(RuntimeInit.java:504) 
        at com.android.internal.os.ZygoteInit.main(ZygoteInit.java:858) 
    #++++++++++++++++++++++++++++++++++++++++++#


//=============================================================================
// ECG "测量超时，请重新测量！"
//=============================================================================
// 这个字符串有两个地方显示，但是实测是在下面这里命中的
EcgMeasureHolder::Runnable()
// 另外一个地方是这里，是取数据那里的一个计时器，也许是因为比上个要晚结束，所以没有命中
EcgPresenterImpl::sendWave()
// TODO: 还有没有其他地方是退出 ECG 测量的？正常结束是在哪里？此时需要给下位机发送停止测量指令
// TODO: 下位机也要做保护，持续发送数据一定时间后，要自动停止。避免上位机忘了下发停止指令


// 如果是 timeRunnable 倒计时20秒到了
EcgMeasureHolder::remove() ->
EcgMeasureHolder::MeasureListener::measureOverTime() ->
MeasureEcgFragment:: -find-> measureError()

// 测量成功应该调用的是：
EcgPresenterImpl::send12LeadDiaResult() -->
MeasureEcgFragment::measureSuccess()
// 意思是12道诊断结束才算是测量成功

//=============================================================================
// 心电波形数据的流向
//=============================================================================
BluetoothLeService::onCharacteristicChanged() ->
DataHandlerUtil::handle() ->
DataHandlerUtil::handleWavePkg() ->
AIDLServer::mHandler() { sendMsg.sendWave() } ->
EcgPresenterImpl::sendWave() { view.addEcgWaveData() }	->
                                     ┌{ ecgWave.addEcgData() }
MeasureEcgFragment::addEcgWaveData() ┤
                                     └{ ecgHolder.addEcgData() } ->
EcgMeasureHolder::addEcgData() ->
EcgViewFor12::addEcgData() { ecg1Data.add(data) } -> // 将波形数据添加到 ecg1Data 中

//=============================================================================
快速测量界面：MeasureQuicklyFragment
控件在这个界面上。
btnSpo2StartMeasure (R.id.btn_spo2_start_measure)

================ 血压启动测量 ================
MeasureQuicklyFragment::onClick() ->
EchoServerEncoder::setNibpConfig() ->
EchoServerEncoder::sendData(Context context, ...)

================ 蓝牙接收血压测量结果 ================

================ 接收蓝牙数据 ================
BluetoothLeService::onCharacteristicChanged() ->
DataHandlerUtil::handle() ->
┌handleTrendPkg()	┐
┤handleWavePkg()	├->
└					┘
AIDLServer::mHandler() ->
┌sendMsg.sendTrend()	┐
┤sendMsg.sendWave()	├->
└						┘

┌QuicklyPresenterImpl::sendTrend()	├
┤Spo2PresenterImpl::sendWave()		├wave->
└

-wave-> MeasureSpo2Fragment::spo2WaveData() ->
WaveFormSpo2::setData()	┑
						│把数据更新到画波形的缓冲区 wave[] 中
						↓
=============== 画波形 ================
WaveFormSpo2::update()


Spo2PresenterImpl 这个是做什么的？


spo2Checking



//=============================================================================
// SpO2 测量失败，测量超时
//=============================================================================

// countDown 一直在 ++ ，没有触发到 停止 的语句
QuicklyPresenterImpl::timeRunnable() -> {countDown >= 20} ->
// 显示 Toast("测量失败，测量超时")
MeasureQuicklyFragment::showSpo2Status()

// 应该在测量的20秒中，因为满足测量结束的要求，在
QuicklyPresenterImpl::sendTrend()
// 中调用
QuicklyPresenterImpl::stopCountDown();

// 但是没调用到的原因是，在启动测量后
spo2Checking=false // 应该是 true

// 只有在这个函数中才会将 spo2Checking = true
QuicklyPresenterImpl::startSpo2Measure()
// 但是被意外地赋值成了 false


//=============================================================================
// ECG无法启动测量
//=============================================================================
// 是因为在onClick()函数中
MeasureEcgFragment::onClick() -> {isEcgConnect == false}
// 程序启动后，isEcgConnect 显式赋值只运行到了
MeasureEcgFragment::onResume() -> {isEcgConnect = false}
// 程序中显式 isEcgConnect 赋值为 true 的地方只有
MeasureEcgFragment::setEcgConnectStatus()

// TODO:
// 调用 MeasureEcgFragment::setEcgConnectStatus() 的有两个地方
// 有可能是蓝牙上发ECG导联状态时触发其中一个
1、EcgPresenterImpl::sendConfig()
2、MeasureEcgFragment::onResume()

//=============================================================================
// 给蓝牙写数据可以参考
//=============================================================================
MeasureActivity::sendData( byte[] data) {
	if( writeCharacteristic != null ) {
		BluetoothLeService.writeCharacteristicGattDb( writeCharacteristic, data );
	}
}


//=============================================================================
//=============================================================================



把PC2设置成AD采样，附加功能的AD123是什么意思？

苍月的十字架

=========================================
stm32之ADC应用实例（单通道、多通道、基于DMA）
https://blog.csdn.net/weixin_42653531/article/details/81123770

RCC_ADCCLKConfig()
ADC_SampleTime_239Cycles5 但是有 ADC_SampleTime_3Cycles 等等
ADC_ResetCalibration
ADC_GetResetCalibrationStatus
ADC_GetCalibrationStatus
ADC_SoftwareStartConvCmd 但有 ADC_SoftwareStartConv

ADC笔记
https://www.jianshu.com/p/d07558b3382e


我们用的是：
PC2
ADC_Channel_12
我们用的是ADC几？由你决定

问题：
1、DMA只有两个吗？
	RCC_AHB1Periph_DMA1
	RCC_AHB1Periph_DMA2
=====================================

$ git log --pretty=oneline
96bd126edebefd82ef32c3cbd75049b0c30877e1 (HEAD -> master, origin/master) MODIFY: 统一了一下串口输出的接口函数
1d448cb378b15570f503b6423da0ff7f55cd79cb ADD: 把UART5、USART6给配置好了，可以读写了。
b4febc772b536466490238abeb6b66646f608373 整理代码。
6570ed70a3566f793ac3bef0dd69e182485fb256 ADD: 如果扫描到指定名称的设备时，就停止扫描
14057c9bded33a4f457a4e43dd199d5f764ae1b7 ADD: 在 BuffLink 中自制了一个线程锁，但性能没有测试，

$ git reset --hard [CommitID]


		//-------------------------------- {
		{
			char debugStr[100];
			for(int i = 0; i < nodeLen; i++) {
				sprintf(debugStr, "%X ", trendNode[i]);
				printStr(debugStr);
			}
			printStr("\n");
		}
		//-------------------------------- }


0x53, 0x4E, 0x26, 0x00, 0x0A, 0x08,  // 协议头
0x00, 0x01, 0x00, 0x2A,              // 数据类型、校正码
0x14, 0x5, 0x3, 0xC, 0x1B,           // 年月日时分
0x00, 0x0F, 0x1, 0x29, 0x0,          // 测量值、温度、单位
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0xDF, // 校验和





★☆○●◎◇◆□■△▲ ＿ ￣＿￣ ¯_ _ ＿ ¯ ￣ ­ ˇ^
╭ ╮╯╰「」

𠃎𠃍 𠃊
↖↑↗   ◤◥
← →   ◣◢
↙↓↘
┏ ┳ ┓ ━┃┌┬┐ ┍┑  ┏━┓  ┍┑
┣ ╋ ┫     ├┼┤ ┕┙  ┃  ┃  ││▔
┗ ┻ ┛     └┴┘       ┗━┛  ┕┙
╭ ─ ╮    ╭╮    ▁━▔ ▏＿_¯￣
│ ╳ │    ╰╯
╰ ─ ╯
===================================================
typedef enum {
	BLE_INIT_SETP_NONE = 0,
	BLE_INIT_SETP_RST,			// 1
	BLE_INIT_SETP_INAT,			// 2 *
	BLE_INIT_SETP_GETNAME,		// 3 *
	BLE_INIT_SETP_SETNAME,		// 4
	BLE_INIT_SETP_GETMODE,		// 5 *
	BLE_INIT_SETP_SETMODE,		// 6
	BLE_INIT_SETP_GETUUID,		// 7
	BLE_INIT_SETP_SETUUIDA,		// 8
	BLE_INIT_SETP_SETUUIDB,		// 9
	BLE_INIT_SETP_SETUUIDC,		// 10
	BLE_INIT_SETP_GETMAC,		// 11 *
	BLE_INIT_SETP_GETLINK,		// 12					从 17		进来 ]-- 改从3、4进
	BLE_INIT_SETP_DISCON,		// 13
	BLE_INIT_SETP_SCAN,			// 14 **	<< XX	√
	BLE_INIT_SETP_GETAUTO,		// 15 *		<< XX	√ 	从 3、4		进来 ] ━ 3、4直接进12
	BLE_INIT_SETP_SETAUTO,		// 16		<< XX	√ 	从 15		进来 ┑▁ 只要从15断
	BLE_INIT_SETP_GETAUTOADD,	// 17		<< XX	√ 	从 15、16	进来 ┙▔ 开就行了
	BLE_INIT_SETP_SETAUTOADD,	// 18		<< XX	√
	BLE_INIT_SETP_OUTAT,		// 19
	BLE_INIT_SETP_CONN,			// 20
	BLE_INIT_SETP_DATA,			// 21
}BLE_INIT_STEP;
===================================================
	 ┏→ 19 → 21 	>>可以收发数据
12 ━┫
	 ┗→ 14 		>>循环待机

 : 2 :
 : 5 :
 : 11 :
 : 3 :
 : 15 :
 : 17 :
 : 12 :
 : 19 :		BLE_INIT_SETP_OUTAT
 : 21 :		BLE_INIT_SETP_DATA
↑↑↑↑↑↑↑ 可以收发数据

 : 2 :   <<< 断开连接后的第一帧是这样的
 : 5 :
 : 11 :
 : 3 :		BLE_INIT_SETP_GETNAME
 : 15 :		BLE_INIT_SETP_GETAUTO		<< XX	√
 : 17 :		BLE_INIT_SETP_GETAUTOADD	<< XX	√
 : 12 :		BLE_INIT_SETP_GETLINK
 : 14 :		BLE_INIT_SETP_SCAN			<< XX	√
↑↑↑↑↑↑↑ 断开连接后

↓↓↓↓↓↓↓ 断开连接后第二帧，及以后的都是这样的。但新主板一直是这个状态循环
 : 1 :		BLE_INIT_SETP_RST
 : 0 :		BLE_INIT_SETP_NONE
 : 2 :		BLE_INIT_SETP_INAT
 : 5 :		BLE_INIT_SETP_GETMODE
 : 11 :		BLE_INIT_SETP_GETMAC
 : 3 :		BLE_INIT_SETP_GETNAME
 : 15 :		BLE_INIT_SETP_GETAUTO		<< XX	√
 : 17 :		BLE_INIT_SETP_GETAUTOADD	<< XX	√
 : 12 :		BLE_INIT_SETP_GETLINK
 : 14 :		BLE_INIT_SETP_SCAN			<< XX	√

==============================================
↓↓↓↓↓↓↓ 离线时会重复下面的状态
 : 2 :		BLE_INIT_SETP_INAT
 : 5 :		BLE_INIT_SETP_GETMODE
 : 11 :		BLE_INIT_SETP_GETMAC
 : 3 :		BLE_INIT_SETP_GETNAME
 : 12 :		BLE_INIT_SETP_GETLINK
 : 1 :		BLE_INIT_SETP_RST
 : 0 :		BLE_INIT_SETP_NONE
↑↑↑↑↑↑↑ 离线

--------------------------------------
↓↓↓↓↓↓↓ 直到连线后进入这个状态
 : 2 :		BLE_INIT_SETP_INAT
 : 5 :		BLE_INIT_SETP_GETMODE
 : 11 :		BLE_INIT_SETP_GETMAC
 : 3 :		BLE_INIT_SETP_GETNAME
 : 12 :		BLE_INIT_SETP_GETLINK
 : 19 :		BLE_INIT_SETP_OUTAT
 : 21 :		BLE_INIT_SETP_DATA
↑↑↑↑↑↑↑ 停在这里进行数据传输


///////////////////////////////////////////////////////////////////////////////////////////////////
// bluetooth.c
// 2020.05.09 Wu Yin
// 一秒定时器
///////////////////////////////////////////////////////////////////////////////////////////////////
static void _timerByCheckTime() {
	static uint32_t lastTime = 0;

	if(OSTimeGet() - lastTime < T_1S) {
		return;
	}
	lastTime = OSTimeGet();

	_checkBtLinkStatus();

	// TODO:
	// For debug
	if(BLE_INIT_SETP_DATA == Ble_Global.Ble_Init_Step) {
		BluetoothWrite(">>>>>", 5);
	}

}

186 6581 8916 周 稳恒深圳销售

--------------------------------------





0x00 = 0
0x01 = 1
0x03 = 3
.
.
.
0x7E = 126
0x7F = 127
0x80(128) = -128	// 128 +128 = 256
0x81(129) = -127	// 129 + 127 = 256
.
.
.
0xFD(253) = -3		// 253 + 3 = 256
0xFE(254) = -2		// 254 + 2 = 256
0xFF(255) = -1		// 255 + 1 = 256

------------------------------------

// 自定义CH协议ID
0x20 = 32    // Len=100		SPO2波形
0x21 = 33    // Len=7		SPO2探头状态
0x22 = 34    // Len=9		SPO2趋势值/脉率

// AppDevice协议ID
0xC9 = 201 // SpO2波形
0xCA = 202 // SpO2趋势值
0xCB = 203 // SpO2 PR值

//----------自定义CH----------
[0] = FF
[1] = Len
[2] = ID
[3] = SerialCnt
[4] = CheckSum

//------------AppDevice协议----------
//************ SpO2趋势值 ************
//--------包头--------
[0] = 0xFF
---
[1] = 0		// 包长度
[2] = 0x21	// 33
---
[3] = 0x51		// 趋势数据包ID
---
[4] = 0		// 序列号
[5] = 0		// SerialCnt
---
[6] = 0		// 校验和
[7] = 0		// CheckSum
//--------包体--------
[8] = 0
[9] = 0
[10] = 0
[11] = 2		// 参数个数
---
[12] = 0		// 当前时间
[13] = 0
[14] = 0
[15] = 0
[16] = 0
[17] = 0
[18] = 0
---
[19] = 0		// 保留字节
[20] = 0		// 保留字节
---// 参数1
[21] = 0
[22] = 0xCA		// SpO2趋势值ID
---
[23] = 0		// SpO2趋势值
[24] = 0
[25] = 0x23		// 9000，90放大100倍
[26] = 0x28
---// 参数2
[27] = 0
[28] = 0xCB		// SpO2 PR值
---
[29] = 0		// SpO2 PR值
[30] = 0
[31] = 0x17		// 6000，60放大100倍
[32] = 0x70

byte SpO2Trend[33] = {0xFF, 0, 0x21, 0x51, 0, 0, 0, 0,
					0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0
					0, 0xCA, 0, 0, 0x23, 0x28,
					0, 0xCB, 0, 0, 0x17, 0x70};

//************ SpO2探头状态 ************
//--------包头--------
[0] = 0xFF
//---包长度
[1] = 0
[2] = 0x0E	// 14
//---配置包ID
[3] = 0x24		// SpO2配置包ID
//---序列号
[4] = 0
[5] = 0		// SerialCnt
//---校验和
[6] = 0
[7] = 0		// CheckSum
//--------包体--------
//---配置类型
[8] = 0
[9] = 0x05	// 探头状态
//---配置值
[10] = 0
[11] = 0
[12] = 0
[13] = 0x01	// 探头未接

byte SpO2SensorSt[14] = {0xFF, 0, 0x0E, 0x24, 0, 0, 0, 0,
						0, 0x05, 0, 0, 0, 0x01};



//************ SpO2参数状态包 ************
//--------包头--------
[0] = 0xFF
//---包长度
[1] = 0
[2] = 0x54	// 84
//---命令字ID
[3] = 0x12	// 参数状态包
//---序列号
[4] = 0
[5] = 0		// SerialCnt
//---校验和
[6] = 0
[7] = 0		// CheckSum
//--------包体--------
//---参数名称
[8] = 0
[9] = 200
//---参数状态 1:激活;0:不激活
[10] = 1
//---波形采样率
[11] = 0
[12] = 125
//---波形最大值
[13] = 0
[14] = 255
//---波形最小值
[15] = 0
[16] = 0
//---波形字节数
[17] = 2
//---波形有效Bit数
[18] = 8
//---保留字节
[19] = 0
[20] = 0
//---硬件名称
[21]*32
//---硬件版本
[53]*32


//************ SpO2波形数据 ************
//--------包头--------
[0] = 0xFF
//---包长度
[1] = 0x0E		// 270
[2] = 0x01
//---命令字ID
[3] = 0x52		// 波形数据包
//---序列号
[4] = 0
[5] = 0			// SerialCnt
//---校验和
[6] = 0
[7] = 0			// CheckSum
//--------包体--------
//---参数类型
[8] = 0xC9		// 201
[9] = 0
//---时间戳
[10] = 0
[11] = 0
[12] = 0
[13] = 0
[14] = 0
[15] = 0
[16] = 0
//---保留字节
[17] = 0
[18] = 0
//---波形长度
[19] = 0
[20] = 250
//---波形数据
[21]*250

//************ NIBP参数状态包 ************

//************ NIBP配置包-启动测量 ************ √
//--------包头--------
[0] = 0xFF
//---包长度
[1] = 0x0E		// 14
[2] = 0x00
//---命令字ID
[3] = 0x25		// 37
//---序列号
[4] = 0
[5] = 0			// SerialCnt
//---校验和
[6] = 0x51		// CheckSum
[7] = 0
//--------包体--------
//---配置类型
[8] = 0x05
[9] = 0x00
//---配置值
[10] = 0
[11] = 0
[12] = 0
[13] = 0x00		// 0:测量

//************ NIBP配置包-停止测量 ************ √
//--------包头--------
[0] = 0xFF
//---包长度
[1] = 0x0E		// 14
[2] = 0
//---命令字ID
[3] = 0x25
//---序列号
[4] = 0
[5] = 0
//---校验和
[6] = 0
[7] = 0
//--------包体--------
//---配置类型
[8] = 0x06
[9] = 0x00
//---配置值
[10] = 0
[11] = 0
[12] = 0
[13] = 0

//************ NIBP配置包-袖带压力值 ************
//--------包头--------
[0] = 0xFF
//---包长度
[1] = 0x00
[2] = 0x0E		// 14
//---命令字ID
[3] = 0x25		// 37
//---序列号
[4] = 0
[5] = 0			// SerialCnt
//---校验和
[6] = 0
[7] = 0			// CheckSum
//--------包体--------
//---配置类型
[8] = 0
[9] = 0x04
//---配置值
[10] = 0		// 压力值 0~300 mmHg
[11] = 0
[12] = 0
[13] = 0



//************ NIBP趋势值 ************
//--------包头--------
[0] = 0xFF
//---包长度
[1] = 0x2D		// 45
[2] = 0x00
//---命令字ID
[3] = 0x51		// 81
//---序列号
[4] =
[5] =
//---校验和
[6] =
[7] =
//--------包体--------
//---参数数量
[8] = 4									[0]
[9] = 0									[1]
[10] = 0								[2]
[11] = 0								[3]
//---时间戳
[12] = 									[4]
[13] = 									[5]
[14] = 									[6]
[15] = 									[7]
[16] = 									[8]
[17] = 									[9]
[18] = 									[10]
//---保留字节
[19] = 									[11]
[20] = 									[12]
//--------参数1：收缩压--------
//---参数类型
[21] = 0xF5		// NIBP_SYS = 501		[13]
[22] = 0x01								[14]
//---参数值
[23] = 0xF8		// 110 * 100			[15]
[24] = 0x2A								[16]
[25] = 									[17]
[26] = 									[18]
//--------参数2：舒张压--------
//---参数类型
[27] = 0xF6		// NIBP_DIA = 502;		[19]
[28] = 0x01								[20]
//---参数值
[29] = 0x28			// 90 * 100			[21]
[30] = 0x23								[22]
[31] = 									[23]
[32] = 									[24]
//--------参数3：平均压--------
//---参数类型
[33] = 0xF7		// NIBP_MAP = 503;		[25]
[34] = 0x01								[26]
//---参数值
[35] = 0x40		// 80 * 100				[27]
[36] = 0x1F								[28]
[37] = 									[29]
[38] = 									[30]
//--------参数4：脉率--------
//---参数类型
[39] = 0xF8		//NIBP_PR = 504;		[31]
[40] = 0x01								[32]
//---参数值
[41] = 0x70		// 60 * 100				[33]
[42] = 0x17								[34]
[43] = 									[35]
[44] = 									[36]




MicSendProtocol::_sendData()






big:
FF 20 3A 20 30 20 3A 20 20 0A





'C' - 0x43 - 0d67
'M' - 0x4D - 0d77
'D' - 0x44 - 0d68
':' - 0x3A - 0d58














































