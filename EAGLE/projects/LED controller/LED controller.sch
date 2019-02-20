<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="8.2.1">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
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
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
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
<library name="customs">
<packages>
<package name="N14">
<pad name="P$1" x="0" y="0" drill="0.6" shape="long"/>
<pad name="P$2" x="0" y="-2.54" drill="0.6" shape="long"/>
<pad name="P$3" x="0" y="-5.08" drill="0.6" shape="long"/>
<pad name="P$4" x="0" y="-7.62" drill="0.6" shape="long"/>
<pad name="P$5" x="0" y="-10.16" drill="0.6" shape="long"/>
<pad name="P$6" x="0" y="-12.7" drill="0.6" shape="long"/>
<pad name="P$7" x="0" y="-15.24" drill="0.6" shape="long"/>
<pad name="P$8" x="7.62" y="-15.24" drill="0.6" shape="long"/>
<pad name="P$9" x="7.62" y="-12.7" drill="0.6" shape="long"/>
<pad name="P$10" x="7.62" y="-10.16" drill="0.6" shape="long"/>
<pad name="P$11" x="7.62" y="-7.62" drill="0.6" shape="long"/>
<pad name="P$12" x="7.62" y="-5.08" drill="0.6" shape="long"/>
<pad name="P$13" x="7.62" y="-2.54" drill="0.6" shape="long"/>
<pad name="P$14" x="7.62" y="0" drill="0.6" shape="long"/>
<wire x1="6.477" y1="-16.002" x2="6.477" y2="1.016" width="0.127" layer="21"/>
<wire x1="6.477" y1="1.016" x2="4.826" y2="1.016" width="0.127" layer="21"/>
<wire x1="4.826" y1="1.016" x2="3.937" y2="0.127" width="0.127" layer="21" curve="-90"/>
<wire x1="3.937" y1="0.127" x2="3.683" y2="0.127" width="0.127" layer="21"/>
<wire x1="3.683" y1="0.127" x2="2.794" y2="1.016" width="0.127" layer="21" curve="-90"/>
<text x="4.445" y="-12.192" size="1.27" layer="21" rot="R90">74AHCT125</text>
<wire x1="2.794" y1="1.016" x2="1.143" y2="1.016" width="0.127" layer="21"/>
<wire x1="1.143" y1="1.016" x2="1.143" y2="-16.002" width="0.127" layer="21"/>
<wire x1="1.143" y1="-16.002" x2="6.477" y2="-16.002" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="74AHCT125">
<pin name="1!OE!" x="-27.94" y="5.08" length="middle"/>
<pin name="1A" x="-27.94" y="2.54" length="middle"/>
<pin name="1Y" x="-27.94" y="0" length="middle"/>
<pin name="2!OE!" x="-27.94" y="-2.54" length="middle"/>
<pin name="2A" x="-27.94" y="-5.08" length="middle"/>
<pin name="2Y" x="-27.94" y="-7.62" length="middle"/>
<pin name="GND" x="-27.94" y="-10.16" length="middle"/>
<pin name="3Y" x="2.54" y="-10.16" length="middle" rot="R180"/>
<pin name="3A" x="2.54" y="-7.62" length="middle" rot="R180"/>
<pin name="3!OE!" x="2.54" y="-5.08" length="middle" rot="R180"/>
<pin name="4Y" x="2.54" y="-2.54" length="middle" rot="R180"/>
<pin name="4A" x="2.54" y="0" length="middle" rot="R180"/>
<pin name="4!OE!" x="2.54" y="2.54" length="middle" rot="R180"/>
<pin name="VCC" x="2.54" y="5.08" length="middle" rot="R180"/>
<wire x1="-22.86" y1="7.62" x2="-2.54" y2="7.62" width="0.254" layer="94"/>
<wire x1="-2.54" y1="7.62" x2="-2.54" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-12.7" x2="-22.86" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-12.7" x2="-22.86" y2="7.62" width="0.254" layer="94"/>
<text x="-20.32" y="-15.24" size="1.778" layer="94">74AHCT125</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="74AHCT125">
<gates>
<gate name="G$1" symbol="74AHCT125" x="-25.4" y="12.7"/>
</gates>
<devices>
<device name="N14" package="N14">
<connects>
<connect gate="G$1" pin="1!OE!" pad="P$1"/>
<connect gate="G$1" pin="1A" pad="P$2"/>
<connect gate="G$1" pin="1Y" pad="P$3"/>
<connect gate="G$1" pin="2!OE!" pad="P$4"/>
<connect gate="G$1" pin="2A" pad="P$5"/>
<connect gate="G$1" pin="2Y" pad="P$6"/>
<connect gate="G$1" pin="3!OE!" pad="P$10"/>
<connect gate="G$1" pin="3A" pad="P$9"/>
<connect gate="G$1" pin="3Y" pad="P$8"/>
<connect gate="G$1" pin="4!OE!" pad="P$13"/>
<connect gate="G$1" pin="4A" pad="P$12"/>
<connect gate="G$1" pin="4Y" pad="P$11"/>
<connect gate="G$1" pin="GND" pad="P$7"/>
<connect gate="G$1" pin="VCC" pad="P$14"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
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
<symbol name="GND" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="VCC" library_version="1">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND" library_version="1">
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
<deviceset name="VCC" prefix="P+" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
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
<library name="wirepad" urn="urn:adsk.eagle:library:412">
<description>&lt;b&gt;Single Pads&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1,6/0,9" library_version="1">
<description>&lt;b&gt;THROUGH-HOLE PAD&lt;/b&gt;</description>
<wire x1="-0.508" y1="0.762" x2="-0.762" y2="0.762" width="0.1524" layer="21"/>
<wire x1="-0.762" y1="0.762" x2="-0.762" y2="0.508" width="0.1524" layer="21"/>
<wire x1="-0.762" y1="-0.508" x2="-0.762" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="-0.762" y1="-0.762" x2="-0.508" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="0.508" y1="-0.762" x2="0.762" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="0.762" y1="-0.762" x2="0.762" y2="-0.508" width="0.1524" layer="21"/>
<wire x1="0.762" y1="0.508" x2="0.762" y2="0.762" width="0.1524" layer="21"/>
<wire x1="0.762" y1="0.762" x2="0.508" y2="0.762" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.635" width="0.1524" layer="51"/>
<pad name="1" x="0" y="0" drill="0.9144" diameter="1.6002" shape="octagon"/>
<text x="-0.762" y="1.016" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="0.6" size="0.0254" layer="27">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="PAD" library_version="1">
<wire x1="-1.016" y1="1.016" x2="1.016" y2="-1.016" width="0.254" layer="94"/>
<wire x1="-1.016" y1="-1.016" x2="1.016" y2="1.016" width="0.254" layer="94"/>
<text x="-1.143" y="1.8542" size="1.778" layer="95">&gt;NAME</text>
<text x="-1.143" y="-3.302" size="1.778" layer="96">&gt;VALUE</text>
<pin name="P" x="2.54" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="1,6/0,9" prefix="PAD" uservalue="yes" library_version="1">
<description>&lt;b&gt;THROUGH-HOLE PAD&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="PAD" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1,6/0,9">
<connects>
<connect gate="1" pin="P" pad="1"/>
</connects>
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
<part name="U$1" library="customs" deviceset="74AHCT125" device="N14"/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="RPGPIO" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="1,6/0,9" device=""/>
<part name="LEDDIN" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="1,6/0,9" device=""/>
<part name="RPGND" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="1,6/0,9" device=""/>
<part name="LEDGND" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="1,6/0,9" device=""/>
<part name="LEDVCC" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="1,6/0,9" device=""/>
<part name="VCC" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="1,6/0,9" device=""/>
<part name="GND" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="1,6/0,9" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="50.8" y="58.42"/>
<instance part="GND1" gate="1" x="43.18" y="30.48"/>
<instance part="P+1" gate="VCC" x="33.02" y="35.56"/>
<instance part="RPGPIO" gate="1" x="5.08" y="60.96"/>
<instance part="LEDDIN" gate="1" x="-5.08" y="58.42"/>
<instance part="RPGND" gate="1" x="20.32" y="27.94" rot="R180"/>
<instance part="LEDGND" gate="1" x="20.32" y="35.56" rot="R180"/>
<instance part="LEDVCC" gate="1" x="20.32" y="43.18" rot="R180"/>
<instance part="VCC" gate="1" x="35.56" y="30.48" rot="R180"/>
<instance part="GND" gate="1" x="45.72" y="35.56" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
<net name="VCC" class="0">
<segment>
<pinref part="P+1" gate="VCC" pin="VCC"/>
<wire x1="33.02" y1="33.02" x2="33.02" y2="30.48" width="0.1524" layer="91"/>
<pinref part="VCC" gate="1" pin="P"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="VCC"/>
<wire x1="53.34" y1="63.5" x2="55.88" y2="63.5" width="0.1524" layer="91"/>
<label x="55.88" y="63.5" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LEDVCC" gate="1" pin="P"/>
<wire x1="17.78" y1="43.18" x2="15.24" y2="43.18" width="0.1524" layer="91"/>
<label x="12.7" y="43.18" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="43.18" y1="33.02" x2="43.18" y2="35.56" width="0.1524" layer="91"/>
<pinref part="GND" gate="1" pin="P"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="1!OE!"/>
<wire x1="22.86" y1="63.5" x2="20.32" y2="63.5" width="0.1524" layer="91"/>
<label x="15.24" y="63.5" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="22.86" y1="48.26" x2="20.32" y2="48.26" width="0.1524" layer="91"/>
<label x="15.24" y="48.26" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="RPGND" gate="1" pin="P"/>
<wire x1="17.78" y1="27.94" x2="15.24" y2="27.94" width="0.1524" layer="91"/>
<label x="12.7" y="27.94" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="17.78" y1="35.56" x2="15.24" y2="35.56" width="0.1524" layer="91"/>
<pinref part="LEDGND" gate="1" pin="P"/>
<label x="12.7" y="35.56" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="1A"/>
<pinref part="RPGPIO" gate="1" pin="P"/>
<wire x1="22.86" y1="60.96" x2="7.62" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="1Y"/>
<pinref part="LEDDIN" gate="1" pin="P"/>
<wire x1="22.86" y1="58.42" x2="-2.54" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, Eagle supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
</compatibility>
</eagle>