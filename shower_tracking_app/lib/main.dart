import 'dart:io';

import 'package:flutter/material.dart';
<<<<<<< Updated upstream
import 'package:shower_tracking_app/pages/splash_screen.dart';
import 'package:shower_tracking_app/router.dart';
=======
import 'package:shower_tracking_app/components/bottom_bar.dart';
import 'package:shower_tracking_app/components/history.dart';
import 'package:shower_tracking_app/components/ranking.dart';
import 'package:shower_tracking_app/components/tracker.dart';
import 'dart:ffi' as ffi;
import 'package:path/path.dart' as path;

>>>>>>> Stashed changes

// FFI signature of the C function
typedef SignalProcessFunc = ffi.Void Function();
// Dart type definition for calling the C foreign function
typedef SignalProcess = void Function();
void main() {
<<<<<<< Updated upstream
  runApp(const App());
=======
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
>>>>>>> Stashed changes
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
