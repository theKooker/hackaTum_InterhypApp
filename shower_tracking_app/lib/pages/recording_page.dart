import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class RecordingPage extends StatefulWidget {
  const RecordingPage({Key? key}) : super(key: key);
  
  @override
  _RecordingPageState createState() => _RecordingPageState();
}

class _RecordingPageState extends State<RecordingPage> {
  var button_string = "assets/images/Design_startLifted.png";
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(
        children: [
          Image.asset("assets/images/Design_BG.png",),
          Column(crossAxisAlignment: CrossAxisAlignment.start, children: [
            Center(
              child: Image.asset("assets/images/Design_shower.png"),
            ),
            Center(
              child:
                  Image.asset("assets/images/Design_waterStreamSeamless.png"),
            ),
          ]),
          Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Center(
                child: Container(
                  height: 0,
                ),
              ),
              Center(
                child: Container(
                  height: 0,
                ),
              ),
              Center(
                child: Container(
                  height: 0,
                ),
              ),
              Center(
                  child: GestureDetector(
                      child:
                          Image.asset(button_string),
                        onTapDown:(value ){
                            setState(() {
                              button_string = "assets/images/Design_startPushed.png";
                            });
                        } ,
                        onTapUp: (value) {
                          
                        },)),
                      

            ],
          )
        ],
      ),
    );
  }
}
