%% Visualize example results for PrimiTect data

addpath('plot_points_3d')
addpath('include')
addpath('include/pc_dist')
addpath('include/pc_vis')
addpath('include/get_inliers')
addpath('overlay_rgb')

in_folder_pc = '../cpp/detect_objects/bin/';
in_folder_res = '../cpp/detect_objects/bin/Release/';

prefix = 'pcd0';

% display distance to closest geometric primitive instance
figure
plot_min_dist(in_folder_pc, in_folder_res, prefix)

% display labels of found geometric primitives
figure
plot_labels(in_folder_pc, in_folder_res, prefix)

return
%%

in_folder_pc = '../data/office/';
in_folder_res = '../data/office/';

prefix = 'dev1n';

% display distance to closest geometric primitive instance
figure
plot_min_dist(in_folder_pc, in_folder_res, prefix)

% display labels of found geometric primitives
figure
plot_labels(in_folder_pc, in_folder_res, prefix)

return

%% Visualize example results for PrimiTect data

in_folder_pc = '../data/primitect/';
in_folder_res = '../ex_results/primitect/';

prefix = '717416';

% display distance to closest geometric primitive instance
figure
plot_min_dist(in_folder_pc, in_folder_res, prefix)

% display labels of found geometric primitives
figure
plot_labels(in_folder_pc, in_folder_res, prefix)

%% Visualize example results for Redwood data

in_folder_pc = '../data/redwood_lod/cylinders/cut2m/';
in_folder_im = '../data/redwood_lod/cylinders/';
in_folder_res = '../ex_results/redwood_lod/cylinders/';

prefix = '01220';

figure
object_overlay(in_folder_pc, in_folder_res, in_folder_im, prefix, 'cylinder')