/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "strip-track",
    .arg = "id",
    .dfault = NULL,
    .desc = "Remove the given track."
  },{
    .name = "set-type",
    .arg = "type",
    .dfault = NULL,
    .desc = "Set the type of the output MIDI file."
  },{
    .name = "merge-track",
    .arg = "track",
    .dfault = NULL,
    .desc = "Set tracks to be merged."
  },{
    .name = "dump",
    .arg = NULL,
    .dfault = NULL,
    .desc = "Print a dump of the parsed MIDI file."
  },{}
};

static scc_param_help_t midi_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t midi_help = {
  .name = "midi",
  .usage = "[OPTIONS] input.mid output.mid",
  .param_help = midi_param_help
};
