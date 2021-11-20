import 'package:flutter/material.dart';
import 'package:shower_tracking_app/components/bottom_bar.dart';
import 'package:shower_tracking_app/components/history.dart';
import 'package:shower_tracking_app/components/ranking.dart';
import 'package:shower_tracking_app/components/tracker.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Shower Tracking App',
      theme: ThemeData(
        textTheme: const TextTheme(
          bodyText1: TextStyle(),
          bodyText2: TextStyle(),
        ).apply(
          bodyColor: Colors.white,
        ),
      ),
      home: const Home(),
    );
  }
}

class Home extends StatelessWidget {
  const Home({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(children: [
        SingleChildScrollView(
          child: Container(
            decoration: const BoxDecoration(
              gradient: LinearGradient(
                begin: Alignment.topRight,
                end: Alignment.bottomLeft,
                colors: [
                  Colors.indigo,
                  Colors.blue,
                ],
              ),
            ),
            child: Column(
              children: [
                Tracker(),
                Ranking(),
                History(),
              ],
            ),
          ),
        ),
        BottomBar(
            index: 0,
            onChange: (value) {},
            items: <BottomBarItem>[
              BottomBarItem(Icons.play_arrow_outlined, label: "Record"), //Recording
              BottomBarItem(Icons.list_alt_outlined), //Ranking
              BottomBarItem(Icons.history_outlined), //History
              BottomBarItem(Icons.account_circle_outlined), //Account
            ],
          ),
      ]),
    );
  }
}
