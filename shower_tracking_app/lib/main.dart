import 'package:flutter/material.dart';
import 'package:shower_tracking_app/pages/splash_screen.dart';
import 'package:shower_tracking_app/router.dart';


void main() {
  runApp(const App());
}

class App extends StatefulWidget {
  const App({Key? key}) : super(key: key);

  @override
  _AppState createState() => _AppState();
}

class _AppState extends State<App> {
  @override
  Widget build(BuildContext context) {

    return MaterialApp(
      title: 'Shower Tracking App',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
        fontFamily: 'custom',
      ),
      home: FutureBuilder(
        future: Future.delayed(const Duration(milliseconds: 1500)),
        builder: (c, s) => s.connectionState == ConnectionState.done
            ? const RouterPage()
            : const SplashScreen(),
      ),
    );
  }
}
