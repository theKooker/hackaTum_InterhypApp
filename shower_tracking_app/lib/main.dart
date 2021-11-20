import 'dart:io';

import 'package:flutter/material.dart';
import 'package:shower_tracking_app/pages/splash_screen.dart';
import 'package:shower_tracking_app/router.dart';

// FFI signature of the C function
typedef SignalProcessFunc = ffi.Void Function();
// Dart type definition for calling the C foreign function
typedef SignalProcess = void Function();
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
      ),
      home: const SplashScreen(), 
    );
  }
}
