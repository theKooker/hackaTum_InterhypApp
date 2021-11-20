import 'package:flutter/material.dart';
import 'package:shower_tracking_app/pages/splash_screen.dart';
import 'package:shower_tracking_app/router.dart';
import 'package:shower_tracking_app/components/bottom_bar.dart';
import 'package:shower_tracking_app/components/history.dart';
import 'package:shower_tracking_app/components/ranking.dart';
import 'package:shower_tracking_app/components/tracker.dart';
import 'dart:ffi' as ffi;
import 'package:path/path.dart' as path;


void main() {
  runApp(const App());
    // Open the dynamic library
  var libraryPath =
      path.join(Directory.current.path, 'hello_library', 'hello.def');

  final dylib = ffi.DynamicLibrary.open(libraryPath);

  // Look up the C function 
  final SignalProcess signalProcess = dylib
      .lookup<ffi.NativeFunction<SignalProcessFunc>>('hello_world')
      .asFunction();
  // Call the function
  signalProcess();
  runApp(const MyApp());
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
      home: FutureBuilder(
        future: Future.delayed(const Duration(milliseconds: 1500)),
        builder: (c, s) => s.connectionState == ConnectionState.done
            ? const RouterPage()
            : const SplashScreen(),
      ),
    );
  }
}
