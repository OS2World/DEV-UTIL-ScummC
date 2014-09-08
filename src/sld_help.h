/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "o",
    .arg = "basename",
    .dfault = "scummc$VERSION",
    .desc = "Set the output file basename."
  },{
    .name = "key",
    .arg = "val",
    .dfault = "0",
    .desc = "Set the output encryption key."
  },{
    .name = "max-local",
    .arg = "val",
    .dfault = "200",
    .desc = "Set the maximal number of object per room in the MAXS block."
  },{
    .name = "max-array",
    .arg = "val",
    .dfault = "100",
    .desc = "Set the maximal number of array in the MAXS block."
  },{
    .name = "max-flobj",
    .arg = "val",
    .dfault = "20",
    .desc = "Set the maximal number of flobject in the MAXS block."
  },{
    .name = "max-inventory",
    .arg = "val",
    .dfault = "20",
    .desc = "Set the maximal number of inventory slot in the MAXS block."
  },{
    .name = "write-room-names",
    .arg = NULL,
    .dfault = NULL,
    .desc = "Fill the RNAM block with the room names."
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
  },{
    .name = "room",
    .arg = NULL,
    .dfault = NULL,
    .desc = "Output .lfl files instead of bundles."
  },{}
};

static scc_param_help_t sld_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t sld_help = {
  .name = "sld",
  .usage = "[OPTIONS] input.roobj ...",
  .param_help = sld_param_help
};
