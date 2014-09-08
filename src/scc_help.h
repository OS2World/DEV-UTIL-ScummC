/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "o",
    .arg = "output",
    .dfault = "output.roobj",
    .desc = "Set the output filename."
  },{
    .name = "I",
    .arg = "dir",
    .dfault = NULL,
    .desc = "Add a directory to be searched for header files."
  },{
    .name = "R",
    .arg = "dir",
    .dfault = NULL,
    .desc = "Add a directory to be searched for resource files."
  },{
    .name = "d",
    .arg = NULL,
    .dfault = NULL,
    .desc = "Generate a make dependency file."
  },{
    .name = "V",
    .arg = "version",
    .dfault = "6",
    .desc = "Set the targeted SCUMM version."
  },{
    .name = "v",
    .arg = NULL,
    .dfault = NULL,
    .desc = "Enable verbose output."
  },{
    .name = "vv",
    .arg = NULL,
    .dfault = NULL,
    .desc = "Enable debug output."
  },{}
};

static scc_param_help_t scc_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t scc_help = {
  .name = "scc",
  .usage = "[OPTIONS] input.scc ...",
  .param_help = scc_param_help
};
