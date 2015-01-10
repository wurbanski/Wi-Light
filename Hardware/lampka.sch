<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.2.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="6" fill="9" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="atmel">
<description>&lt;b&gt;AVR Devices&lt;/b&gt;&lt;p&gt;
Configurable logic, microcontrollers, nonvolatile memories&lt;p&gt;
Based on the following sources:&lt;p&gt;
&lt;ul&gt;
&lt;li&gt;www.atmel.com
&lt;li&gt;CD-ROM : Configurable Logic Microcontroller Nonvolatile Memory
&lt;li&gt;CadSoft download site, www.cadsoft.de or www.cadsoftusa.com , file at90smcu_v400.zip
&lt;li&gt;avr.lbr
&lt;/ul&gt;
&lt;author&gt;Revised by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="DIL08">
<description>&lt;B&gt;Dual In Line&lt;/B&gt;</description>
<wire x1="-5.08" y1="-0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21" curve="180"/>
<wire x1="-5.08" y1="-0.635" x2="-5.08" y2="-2.794" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-2.794" x2="5.08" y2="-2.794" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-2.794" x2="5.08" y2="2.794" width="0.1524" layer="21"/>
<wire x1="5.08" y1="2.794" x2="-5.08" y2="2.794" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="2.794" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<pad name="1" x="-3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="-1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="-3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<text x="-5.3594" y="-2.54" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-3.81" y="-0.9906" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="SOIC8">
<description>&lt;B&gt;Wide Plastic Gull Wing Small Outline Package&lt;/B&gt;</description>
<wire x1="-2.6" y1="2.25" x2="-2.35" y2="2.5" width="0.1524" layer="21" curve="-90"/>
<wire x1="2.35" y1="2.5" x2="2.6" y2="2.25" width="0.1524" layer="21" curve="-90"/>
<wire x1="2.35" y1="-2.5" x2="2.6" y2="-2.25" width="0.1524" layer="21" curve="90"/>
<wire x1="-2.6" y1="-2.25" x2="-2.35" y2="-2.5" width="0.1524" layer="21" curve="90"/>
<wire x1="2.36" y1="-2.5" x2="-2.34" y2="-2.5" width="0.1524" layer="51"/>
<wire x1="-2.34" y1="2.5" x2="2.36" y2="2.5" width="0.1524" layer="51"/>
<wire x1="-2.21" y1="2.5" x2="-2.34" y2="2.5" width="0.1524" layer="21"/>
<wire x1="-1.59" y1="2.5" x2="-0.95" y2="2.5" width="0.1524" layer="21"/>
<wire x1="-0.32" y1="2.5" x2="0.32" y2="2.5" width="0.1524" layer="21"/>
<wire x1="0.95" y1="2.5" x2="1.59" y2="2.5" width="0.1524" layer="21"/>
<wire x1="2.21" y1="2.5" x2="2.36" y2="2.5" width="0.1524" layer="21"/>
<wire x1="2.2" y1="-2.5" x2="2.33" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="1.59" y1="-2.5" x2="0.94" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="0.32" y1="-2.5" x2="-0.33" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="-0.95" y1="-2.5" x2="-1.59" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="-2.21" y1="-2.5" x2="-2.34" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="-2.6" y1="2.25" x2="-2.6" y2="-2.24" width="0.1524" layer="21"/>
<wire x1="2.6" y1="-2.25" x2="2.6" y2="2.25" width="0.1524" layer="21"/>
<circle x="-1.42" y="-1.115" radius="0.5" width="0.0508" layer="21"/>
<smd name="1" x="-1.905" y="-3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="2" x="-0.645" y="-3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="3" x="0.625" y="-3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="4" x="1.895" y="-3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="8" x="-1.905" y="3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="7" x="-0.635" y="3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="6" x="0.635" y="3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="5" x="1.905" y="3.154" dx="0.5" dy="2.2" layer="1"/>
<text x="-2.8575" y="-2.159" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="4.064" y="-2.159" size="1.27" layer="27" ratio="10" rot="R90">&gt;VALUE</text>
<rectangle x1="-2.08" y1="2.5" x2="-1.73" y2="3.4" layer="51"/>
<rectangle x1="-0.81" y1="2.5" x2="-0.46" y2="3.4" layer="51"/>
<rectangle x1="0.46" y1="2.5" x2="0.81" y2="3.4" layer="51"/>
<rectangle x1="1.73" y1="2.5" x2="2.08" y2="3.4" layer="51"/>
<rectangle x1="1.72" y1="-3.4" x2="2.07" y2="-2.5" layer="51"/>
<rectangle x1="0.45" y1="-3.4" x2="0.8" y2="-2.5" layer="51"/>
<rectangle x1="-0.82" y1="-3.4" x2="-0.47" y2="-2.5" layer="51"/>
<rectangle x1="-2.08" y1="-3.4" x2="-1.73" y2="-2.5" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="6-I/O-1">
<wire x1="12.7" y1="-7.62" x2="-12.7" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-7.62" x2="-12.7" y2="10.16" width="0.254" layer="94"/>
<wire x1="-12.7" y1="10.16" x2="12.7" y2="10.16" width="0.254" layer="94"/>
<wire x1="12.7" y1="10.16" x2="12.7" y2="-7.62" width="0.254" layer="94"/>
<text x="-12.7" y="10.922" size="1.778" layer="95">&gt;NAME</text>
<text x="-12.7" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<pin name="(XTAL2)PB4" x="17.78" y="5.08" length="middle" rot="R180"/>
<pin name="(XTAL1)PB3" x="17.78" y="2.54" length="middle" rot="R180"/>
<pin name="(RESET)PB5" x="17.78" y="7.62" length="middle" rot="R180"/>
<pin name="(T0)PB2" x="17.78" y="0" length="middle" rot="R180"/>
<pin name="(AIN1)PB1" x="17.78" y="-2.54" length="middle" rot="R180"/>
<pin name="(AIN0)PB0" x="17.78" y="-5.08" length="middle" rot="R180"/>
<pin name="VCC" x="-17.78" y="-2.54" length="middle" direction="pwr"/>
<pin name="GND" x="-17.78" y="-5.08" length="middle" direction="pwr"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="TINY10" prefix="IC">
<description>&lt;b&gt;MICROCONTROLLER&lt;/b&gt;&lt;p&gt;
1 Kbytes ROM</description>
<gates>
<gate name="G$1" symbol="6-I/O-1" x="0" y="0"/>
</gates>
<devices>
<device name="P" package="DIL08">
<connects>
<connect gate="G$1" pin="(AIN0)PB0" pad="5"/>
<connect gate="G$1" pin="(AIN1)PB1" pad="6"/>
<connect gate="G$1" pin="(RESET)PB5" pad="1"/>
<connect gate="G$1" pin="(T0)PB2" pad="7"/>
<connect gate="G$1" pin="(XTAL1)PB3" pad="2"/>
<connect gate="G$1" pin="(XTAL2)PB4" pad="3"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="VCC" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="S" package="SOIC8">
<connects>
<connect gate="G$1" pin="(AIN0)PB0" pad="5"/>
<connect gate="G$1" pin="(AIN1)PB1" pad="6"/>
<connect gate="G$1" pin="(RESET)PB5" pad="1"/>
<connect gate="G$1" pin="(T0)PB2" pad="7"/>
<connect gate="G$1" pin="(XTAL1)PB3" pad="2"/>
<connect gate="G$1" pin="(XTAL2)PB4" pad="3"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="VCC" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="V+">
<wire x1="0.889" y1="-1.27" x2="0" y2="0.127" width="0.254" layer="94"/>
<wire x1="0" y1="0.127" x2="-0.889" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-0.889" y1="-1.27" x2="0.889" y2="-1.27" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="V+" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="V+" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="V+" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-lsta">
<description>&lt;b&gt;Female Headers etc.&lt;/b&gt;&lt;p&gt;
Naming:&lt;p&gt;
FE = female&lt;p&gt;
# contacts - # rows&lt;p&gt;
W = angled&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="FE08">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<wire x1="-10.16" y1="1.27" x2="-10.16" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.27" x2="-7.874" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-7.874" y1="-1.27" x2="-7.62" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.016" x2="-7.366" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="-1.27" x2="-5.334" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="-1.27" x2="-5.08" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.016" x2="-4.826" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-1.27" x2="-2.794" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-1.27" x2="-2.54" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.016" x2="-2.286" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.27" x2="-0.254" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-1.27" x2="0" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.016" x2="0.254" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.27" x2="0" y2="1.016" width="0.1524" layer="21"/>
<wire x1="0" y1="1.016" x2="-0.254" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="1.27" x2="-2.286" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.27" x2="-2.54" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.016" x2="-2.794" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="1.27" x2="-4.826" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="1.27" x2="-5.08" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.016" x2="-5.334" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="1.27" x2="-7.366" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="1.27" x2="-7.62" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.016" x2="-7.874" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-7.874" y1="1.27" x2="-10.16" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-9.144" y1="0.762" x2="-9.144" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-9.144" y1="0.508" x2="-9.398" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-9.398" y1="0.508" x2="-9.398" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-9.398" y1="-0.508" x2="-9.144" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-9.144" y1="-0.508" x2="-9.144" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-9.144" y1="-0.762" x2="-8.636" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-8.636" y1="-0.762" x2="-8.636" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-8.636" y1="-0.508" x2="-8.382" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-8.382" y1="-0.508" x2="-8.382" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-8.382" y1="0.508" x2="-8.636" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-8.636" y1="0.508" x2="-8.636" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-8.636" y1="0.762" x2="-9.144" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="0.762" x2="-6.604" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="0.508" x2="-6.858" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.858" y1="0.508" x2="-6.858" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.858" y1="-0.508" x2="-6.604" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-0.508" x2="-6.604" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-0.762" x2="-6.096" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-0.762" x2="-6.096" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-0.508" x2="-5.842" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-5.842" y1="-0.508" x2="-5.842" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-5.842" y1="0.508" x2="-6.096" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="0.508" x2="-6.096" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="0.762" x2="-6.604" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="0.762" x2="-4.064" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="0.508" x2="-4.318" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.318" y1="0.508" x2="-4.318" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.318" y1="-0.508" x2="-4.064" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="-0.508" x2="-4.064" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="-0.762" x2="-3.556" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="-0.762" x2="-3.556" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="-0.508" x2="-3.302" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="-0.508" x2="-3.302" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="0.508" x2="-3.556" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="0.508" x2="-3.556" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="0.762" x2="-4.064" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="0.762" x2="-1.524" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="0.508" x2="-1.778" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.778" y1="0.508" x2="-1.778" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.778" y1="-0.508" x2="-1.524" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="-0.508" x2="-1.524" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="-0.762" x2="-1.016" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="-0.762" x2="-1.016" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="-0.508" x2="-0.762" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="-0.508" x2="-0.762" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="0.508" x2="-1.016" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="0.508" x2="-1.016" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="0.762" x2="-1.524" y2="0.762" width="0.1524" layer="51"/>
<wire x1="1.016" y1="0.762" x2="1.016" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.016" y1="0.508" x2="0.762" y2="0.508" width="0.1524" layer="51"/>
<wire x1="0.762" y1="0.508" x2="0.762" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="0.762" y1="-0.508" x2="1.016" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.016" y1="-0.508" x2="1.016" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.016" y1="-0.762" x2="1.524" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.524" y1="-0.762" x2="1.524" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.524" y1="-0.508" x2="1.778" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.778" y1="-0.508" x2="1.778" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.778" y1="0.508" x2="1.524" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.524" y1="0.508" x2="1.524" y2="0.762" width="0.1524" layer="51"/>
<wire x1="1.524" y1="0.762" x2="1.016" y2="0.762" width="0.1524" layer="51"/>
<wire x1="0.254" y1="-1.27" x2="2.286" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.27" x2="2.54" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.016" x2="2.794" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-1.27" x2="4.826" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-1.27" x2="5.08" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.016" x2="5.334" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.334" y1="1.27" x2="5.08" y2="1.016" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.016" x2="4.826" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.826" y1="1.27" x2="2.794" y2="1.27" width="0.1524" layer="21"/>
<wire x1="2.794" y1="1.27" x2="2.54" y2="1.016" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.016" x2="2.286" y2="1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.27" x2="0.254" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.556" y1="0.762" x2="3.556" y2="0.508" width="0.1524" layer="51"/>
<wire x1="3.556" y1="0.508" x2="3.302" y2="0.508" width="0.1524" layer="51"/>
<wire x1="3.302" y1="0.508" x2="3.302" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="3.302" y1="-0.508" x2="3.556" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="3.556" y1="-0.508" x2="3.556" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="3.556" y1="-0.762" x2="4.064" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="4.064" y1="-0.762" x2="4.064" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.064" y1="-0.508" x2="4.318" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.318" y1="-0.508" x2="4.318" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.318" y1="0.508" x2="4.064" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.064" y1="0.508" x2="4.064" y2="0.762" width="0.1524" layer="51"/>
<wire x1="4.064" y1="0.762" x2="3.556" y2="0.762" width="0.1524" layer="51"/>
<wire x1="6.096" y1="0.762" x2="6.096" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.096" y1="0.508" x2="5.842" y2="0.508" width="0.1524" layer="51"/>
<wire x1="5.842" y1="0.508" x2="5.842" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="5.842" y1="-0.508" x2="6.096" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.096" y1="-0.508" x2="6.096" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="6.096" y1="-0.762" x2="6.604" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-0.762" x2="6.604" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-0.508" x2="6.858" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.858" y1="-0.508" x2="6.858" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.858" y1="0.508" x2="6.604" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.604" y1="0.508" x2="6.604" y2="0.762" width="0.1524" layer="51"/>
<wire x1="6.604" y1="0.762" x2="6.096" y2="0.762" width="0.1524" layer="51"/>
<wire x1="10.16" y1="1.27" x2="7.874" y2="1.27" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.27" x2="10.16" y2="1.27" width="0.1524" layer="21"/>
<wire x1="7.874" y1="-1.27" x2="10.16" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.016" x2="7.366" y2="1.27" width="0.1524" layer="21"/>
<wire x1="7.874" y1="1.27" x2="7.62" y2="1.016" width="0.1524" layer="21"/>
<wire x1="7.366" y1="1.27" x2="5.334" y2="1.27" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.016" x2="7.874" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="7.366" y1="-1.27" x2="7.62" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="5.334" y1="-1.27" x2="7.366" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.636" y1="0.762" x2="8.636" y2="0.508" width="0.1524" layer="51"/>
<wire x1="8.636" y1="0.508" x2="8.382" y2="0.508" width="0.1524" layer="51"/>
<wire x1="8.382" y1="0.508" x2="8.382" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="8.382" y1="-0.508" x2="8.636" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="8.636" y1="-0.508" x2="8.636" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="8.636" y1="-0.762" x2="9.144" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="9.144" y1="-0.762" x2="9.144" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="9.144" y1="-0.508" x2="9.398" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="9.398" y1="-0.508" x2="9.398" y2="0.508" width="0.1524" layer="51"/>
<wire x1="9.398" y1="0.508" x2="9.144" y2="0.508" width="0.1524" layer="51"/>
<wire x1="9.144" y1="0.508" x2="9.144" y2="0.762" width="0.1524" layer="51"/>
<wire x1="9.144" y1="0.762" x2="8.636" y2="0.762" width="0.1524" layer="51"/>
<pad name="1" x="-8.89" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-6.35" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-3.81" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="-1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="3.81" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="6.35" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="8.89" y="0" drill="0.8128" shape="long" rot="R90"/>
<text x="-6.35" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-9.398" y="1.524" size="1.27" layer="21" ratio="10">1</text>
<text x="-10.16" y="-2.921" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="8.382" y="1.524" size="1.27" layer="21" ratio="10">8</text>
<rectangle x1="-9.017" y1="0.254" x2="-8.763" y2="0.762" layer="51"/>
<rectangle x1="-9.017" y1="-0.762" x2="-8.763" y2="-0.254" layer="51"/>
<rectangle x1="-6.477" y1="0.254" x2="-6.223" y2="0.762" layer="51"/>
<rectangle x1="-6.477" y1="-0.762" x2="-6.223" y2="-0.254" layer="51"/>
<rectangle x1="-3.937" y1="0.254" x2="-3.683" y2="0.762" layer="51"/>
<rectangle x1="-3.937" y1="-0.762" x2="-3.683" y2="-0.254" layer="51"/>
<rectangle x1="-1.397" y1="0.254" x2="-1.143" y2="0.762" layer="51"/>
<rectangle x1="-1.397" y1="-0.762" x2="-1.143" y2="-0.254" layer="51"/>
<rectangle x1="1.143" y1="0.254" x2="1.397" y2="0.762" layer="51"/>
<rectangle x1="1.143" y1="-0.762" x2="1.397" y2="-0.254" layer="51"/>
<rectangle x1="3.683" y1="0.254" x2="3.937" y2="0.762" layer="51"/>
<rectangle x1="3.683" y1="-0.762" x2="3.937" y2="-0.254" layer="51"/>
<rectangle x1="6.223" y1="0.254" x2="6.477" y2="0.762" layer="51"/>
<rectangle x1="6.223" y1="-0.762" x2="6.477" y2="-0.254" layer="51"/>
<rectangle x1="8.763" y1="0.254" x2="9.017" y2="0.762" layer="51"/>
<rectangle x1="8.763" y1="-0.762" x2="9.017" y2="-0.254" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="FE08-1">
<wire x1="3.81" y1="-10.16" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="1.905" y1="-1.905" x2="1.905" y2="-3.175" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-4.445" x2="1.905" y2="-5.715" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-6.985" x2="1.905" y2="-8.255" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="3.175" x2="1.905" y2="1.905" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="0.635" x2="1.905" y2="-0.635" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="10.795" x2="1.905" y2="9.525" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="8.255" x2="1.905" y2="6.985" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="5.715" x2="1.905" y2="4.445" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="-1.27" y1="12.7" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-10.16" x2="3.81" y2="12.7" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="12.7" x2="3.81" y2="12.7" width="0.4064" layer="94"/>
<text x="-1.27" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.27" y="13.462" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="7" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="8" x="7.62" y="10.16" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="FE08-1" prefix="SV" uservalue="yes">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="FE08-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="FE08">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="display-hp">
<description>&lt;b&gt;Hewlett Packard LED Displays&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="HLMP6">
<description>&lt;b&gt;LED&lt;/b&gt;&lt;p&gt;
2 mm horizontal, RM 2.54 mm</description>
<wire x1="-2.413" y1="-1.27" x2="2.921" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.921" y1="1.27" x2="2.921" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.921" y1="1.27" x2="-2.413" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="-1.27" x2="-2.413" y2="-0.889" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-0.889" x2="-2.794" y2="0.889" width="0.1524" layer="21" curve="-180"/>
<wire x1="-2.794" y1="0.889" x2="-2.413" y2="0.889" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="0.889" x2="-2.413" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-0.889" x2="-2.413" y2="-0.889" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="-0.889" x2="-2.413" y2="0.889" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="0.635" x2="-2.794" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-3.048" y1="0.508" x2="-3.048" y2="-0.508" width="0.1524" layer="21"/>
<wire x1="-3.302" y1="0.254" x2="-3.302" y2="-0.254" width="0.1524" layer="21"/>
<pad name="A" x="-1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="K" x="1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<text x="3.429" y="0.127" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="3.429" y="-1.397" size="1.27" layer="27">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="LED">
<wire x1="1.27" y1="2.54" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="2.54" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="2.54" x2="0" y2="2.54" width="0.254" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="2.54" width="0.1524" layer="94"/>
<wire x1="0" y1="2.54" x2="-1.27" y2="2.54" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="-2.032" y1="1.778" x2="-3.429" y2="0.381" width="0.1524" layer="94"/>
<wire x1="-3.429" y1="0.381" x2="-2.54" y2="0.762" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="0.762" x2="-3.048" y2="1.27" width="0.1524" layer="94"/>
<wire x1="-3.048" y1="1.27" x2="-3.429" y2="0.381" width="0.1524" layer="94"/>
<wire x1="-3.302" y1="-0.762" x2="-2.413" y2="-0.381" width="0.1524" layer="94"/>
<wire x1="-2.413" y1="-0.381" x2="-2.921" y2="0.127" width="0.1524" layer="94"/>
<wire x1="-2.921" y1="0.127" x2="-3.302" y2="-0.762" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="0.635" x2="-3.302" y2="-0.762" width="0.1524" layer="94"/>
<text x="3.302" y="-1.524" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="5.461" y="-1.524" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="K" x="0" y="-2.54" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="A" x="0" y="5.08" visible="off" length="point" direction="pas" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="HLMP6" prefix="D">
<description>&lt;b&gt;LED&lt;/b&gt;&lt;p&gt;
2mm horizontal</description>
<gates>
<gate name="A" symbol="LED" x="0" y="0"/>
</gates>
<devices>
<device name="" package="HLMP6">
<connects>
<connect gate="A" pin="A" pad="A"/>
<connect gate="A" pin="K" pad="K"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="AGILENT TECHNOLOGIES" constant="no"/>
<attribute name="MPN" value="HLMP-6500" constant="no"/>
<attribute name="OC_FARNELL" value="1652490" constant="no"/>
<attribute name="OC_NEWARK" value="40K0088" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="docu-dummy">
<description>Dummy symbols</description>
<packages>
</packages>
<symbols>
<symbol name="RESISTOR">
<wire x1="-2.54" y1="-0.889" x2="2.54" y2="-0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="-0.889" x2="2.54" y2="0" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-0.889" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="-5.08" y1="0" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="5.08" y2="0" width="0.1524" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="R" prefix="R">
<description>&lt;b&gt;RESISTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="ATTINY85" library="atmel" deviceset="TINY10" device="P"/>
<part name="P+1" library="supply1" deviceset="V+" device=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="P+2" library="supply1" deviceset="V+" device=""/>
<part name="NRF_HEADER" library="con-lsta" deviceset="FE08-1" device=""/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="LED" library="display-hp" deviceset="HLMP6" device=""/>
<part name="GND3" library="supply1" deviceset="GND" device=""/>
<part name="R1" library="docu-dummy" deviceset="R" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="ATTINY85" gate="G$1" x="-22.86" y="58.42"/>
<instance part="P+1" gate="1" x="-40.64" y="83.82"/>
<instance part="GND1" gate="1" x="-43.18" y="30.48"/>
<instance part="P+2" gate="1" x="45.72" y="91.44"/>
<instance part="NRF_HEADER" gate="G$1" x="68.58" y="58.42" rot="MR0"/>
<instance part="GND2" gate="1" x="48.26" y="33.02"/>
<instance part="LED" gate="A" x="5.08" y="27.94"/>
<instance part="GND3" gate="1" x="5.08" y="22.86"/>
<instance part="R1" gate="G$1" x="5.08" y="38.1" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="V+" class="0">
<segment>
<pinref part="ATTINY85" gate="G$1" pin="VCC"/>
<pinref part="P+1" gate="1" pin="V+"/>
<wire x1="-40.64" y1="55.88" x2="-40.64" y2="81.28" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="NRF_HEADER" gate="G$1" pin="2"/>
<wire x1="60.96" y1="53.34" x2="45.72" y2="53.34" width="0.1524" layer="91"/>
<pinref part="P+2" gate="1" pin="V+"/>
<wire x1="45.72" y1="53.34" x2="45.72" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="-43.18" y1="33.02" x2="-43.18" y2="53.34" width="0.1524" layer="91"/>
<pinref part="ATTINY85" gate="G$1" pin="GND"/>
<wire x1="-43.18" y1="53.34" x2="-40.64" y2="53.34" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="48.26" y1="35.56" x2="48.26" y2="40.64" width="0.1524" layer="91"/>
<pinref part="NRF_HEADER" gate="G$1" pin="1"/>
<wire x1="48.26" y1="40.64" x2="48.26" y2="45.72" width="0.1524" layer="91"/>
<wire x1="60.96" y1="50.8" x2="48.26" y2="50.8" width="0.1524" layer="91"/>
<wire x1="48.26" y1="50.8" x2="48.26" y2="45.72" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="LED" gate="A" pin="K"/>
<pinref part="GND3" gate="1" pin="GND"/>
</segment>
</net>
<net name="MOSI" class="0">
<segment>
<pinref part="ATTINY85" gate="G$1" pin="(AIN1)PB1"/>
<wire x1="25.4" y1="55.88" x2="-5.08" y2="55.88" width="0.1524" layer="91"/>
<wire x1="25.4" y1="63.5" x2="25.4" y2="55.88" width="0.1524" layer="91"/>
<wire x1="25.4" y1="63.5" x2="63.5" y2="63.5" width="0.1524" layer="91"/>
<label x="7.62" y="55.88" size="1.778" layer="95"/>
</segment>
</net>
<net name="MISO" class="0">
<segment>
<pinref part="ATTINY85" gate="G$1" pin="(AIN0)PB0"/>
<wire x1="-5.08" y1="53.34" x2="27.94" y2="53.34" width="0.1524" layer="91"/>
<wire x1="27.94" y1="53.34" x2="27.94" y2="66.04" width="0.1524" layer="91"/>
<wire x1="27.94" y1="66.04" x2="63.5" y2="66.04" width="0.1524" layer="91"/>
<label x="7.62" y="53.34" size="1.778" layer="95"/>
</segment>
</net>
<net name="CE/IRQ" class="0">
<segment>
<pinref part="NRF_HEADER" gate="G$1" pin="8"/>
<wire x1="60.96" y1="68.58" x2="53.34" y2="68.58" width="0.1524" layer="91"/>
<wire x1="53.34" y1="68.58" x2="53.34" y2="55.88" width="0.1524" layer="91"/>
<wire x1="53.34" y1="55.88" x2="63.5" y2="55.88" width="0.1524" layer="91"/>
<label x="53.34" y="68.58" size="1.778" layer="95"/>
<wire x1="53.34" y1="55.88" x2="33.02" y2="55.88" width="0.1524" layer="91"/>
<wire x1="33.02" y1="55.88" x2="33.02" y2="45.72" width="0.1524" layer="91"/>
<wire x1="33.02" y1="45.72" x2="2.54" y2="45.72" width="0.1524" layer="91"/>
<wire x1="2.54" y1="45.72" x2="2.54" y2="60.96" width="0.1524" layer="91"/>
<pinref part="ATTINY85" gate="G$1" pin="(XTAL1)PB3"/>
<wire x1="2.54" y1="60.96" x2="-5.08" y2="60.96" width="0.1524" layer="91"/>
<junction x="53.34" y="55.88"/>
</segment>
</net>
<net name="SCK" class="0">
<segment>
<pinref part="NRF_HEADER" gate="G$1" pin="5"/>
<wire x1="60.96" y1="60.96" x2="22.86" y2="60.96" width="0.1524" layer="91"/>
<wire x1="22.86" y1="60.96" x2="22.86" y2="58.42" width="0.1524" layer="91"/>
<wire x1="22.86" y1="58.42" x2="-7.62" y2="58.42" width="0.1524" layer="91"/>
<label x="7.62" y="58.42" size="1.778" layer="95"/>
</segment>
</net>
<net name="CSN" class="0">
<segment>
<pinref part="NRF_HEADER" gate="G$1" pin="4"/>
<wire x1="60.96" y1="58.42" x2="30.48" y2="58.42" width="0.1524" layer="91"/>
<wire x1="30.48" y1="58.42" x2="30.48" y2="48.26" width="0.1524" layer="91"/>
<wire x1="30.48" y1="48.26" x2="5.08" y2="48.26" width="0.1524" layer="91"/>
<wire x1="5.08" y1="48.26" x2="0" y2="48.26" width="0.1524" layer="91"/>
<wire x1="0" y1="48.26" x2="0" y2="63.5" width="0.1524" layer="91"/>
<pinref part="ATTINY85" gate="G$1" pin="(XTAL2)PB4"/>
<wire x1="0" y1="63.5" x2="-5.08" y2="63.5" width="0.1524" layer="91"/>
<label x="7.62" y="48.26" size="1.778" layer="95"/>
<wire x1="5.08" y1="43.18" x2="5.08" y2="48.26" width="0.1524" layer="91"/>
<junction x="5.08" y="48.26"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
