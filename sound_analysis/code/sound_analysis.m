file_names = ["C:\Users\Alexander\Documents\Development\Private\Hackathon\HackaTUM\Project\hackaTum_InterhypApp\sound_analysis\sample_data\audio_file_1.aac", ...
    "C:\Users\Alexander\Documents\Development\Private\Hackathon\HackaTUM\Project\hackaTum_InterhypApp\sound_analysis\sample_data\audio_file_2.mp4", ...
    "C:\Users\Alexander\Documents\Development\Private\Hackathon\HackaTUM\Project\hackaTum_InterhypApp\sound_analysis\sample_data\audio_file_3.wav", ...
    "C:\Users\Alexander\Documents\Development\Private\Hackathon\HackaTUM\Project\hackaTum_InterhypApp\sound_analysis\sample_data\audio_file_4.mp4"];
    

%value = test_function(1,4);

frame_time = 1; % in seconds

[y,Fs] = audioread(file_names(4));

N = ceil(size(y, 1) / (Fs * frame_time));

%mask = zeros(1, N);
%mask(13:119) = 1;
%mask(141:333) = 1;
%mask(370:521) = 1;

mask = zeros(1, N);
mask(13:242) = 1;

shower_time = sound_analyzer(y, Fs, frame_time, mask);

disp(shower_time)

%plot(y)