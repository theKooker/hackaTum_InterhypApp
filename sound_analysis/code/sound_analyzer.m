function shower_time = sound_analyzer(signal, Fs, frame_time, mask)
    if size(signal, 2) == 2
        signal = signal(:, 1);
    end
    
    % Normalize Signal
    signal = normalize(signal);
    
    % Padding the signal
    N = ceil(size(signal, 1) / (Fs * frame_time));
    pad_signal = zeros(N*Fs, 1);
    pad_signal(1:size(signal, 1)) = signal;
    
    % Spliting the signal into blocks so we can determine 
    signal_frames = reshape(pad_signal, [Fs * frame_time, N]);

    % Getting features
    features = zeros(2, size(signal_frames, 2));
    power = sum(signal.^2);
    
    for i = 1:size(signal_frames, 2)
        features(1, i) = sum(signal_frames(:, i).^2) / power;
        L = frame_time * Fs;
        Y = fft(signal_frames(:, i));
        P2 = abs(Y/L);
        P1 = P2(1:L/2+1);
        P1(2:end-1) = 2*P1(2:end-1);
        f = Fs*(0:(L/2))/L;
        
        threshold = 1e3;
        max_freq = 13e3;
        P1 = P1(f<max_freq);
        f = f(f<max_freq);
        % Get low / highpass energy ratio
        % Should be updated to a statistical model once ore data is
        % available.
        features(2, i) = sum(P1(f<threshold).^2) / sum(P1(f>=threshold).^2);
        
    end
    
    calc_mask = (features(2, :) < 0.4);
    shower_time = sum(calc_mask);
    
    
    % Calc Accuracy
    %fp = (calc_mask == mask);
    %accuracy = sum(fp)/length(fp);
    %disp(accuracy)
end

