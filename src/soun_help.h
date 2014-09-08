/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "o",
    .arg = "output.soun",
    .dfault = "output.soun",
    .desc = "Set the output file name"
  },{
    .name = "key",
    .arg = "k",
    .dfault = NULL,
    .desc = "Decryption key to use when reading the datafiles."
  },{
    .name = "dbg",
    .arg = NULL,
    .dfault = NULL,
    .desc = "Run in debugger mode."
  },{}
};

static scc_param_help_t MIDI_options_param_help[] = {
  {
    .name = "midi",
    .arg = "file.mid",
    .dfault = NULL,
    .desc = "Use this General MIDI file to create a MIDI block."
  },{}
};

static scc_param_help_t SOUN_options_param_help[] = {
  {
    .name = "adl",
    .arg = "file.mid",
    .dfault = NULL,
    .desc = "Use this Adlib file."
  },{
    .name = "rol",
    .arg = "file.mid",
    .dfault = NULL,
    .desc = "Use this Roland file."
  },{
    .name = "gmd",
    .arg = "file.mid",
    .dfault = NULL,
    .desc = "Use this General MIDI file."
  },{}
};

static scc_param_help_t soun_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{
    .name = "MIDI OPTIONS",
    .group = MIDI_options_param_help
  },{
    .name = "SOUN OPTIONS",
    .group = SOUN_options_param_help
  },{}
};

static scc_help_t soun_help = {
  .name = "soun",
  .usage = "[OPTIONS] [MIDI OPTIONS] [SOUN OPTIONS]",
  .param_help = soun_param_help
};
