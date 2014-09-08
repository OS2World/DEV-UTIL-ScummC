/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "img",
    .arg = "file.bmp",
    .dfault = NULL,
    .desc = "Set the room image file to use. The room image can also be loaded from the GUI."
  },{
    .name = "scal",
    .arg = "file.scal",
    .dfault = NULL,
    .desc = "Load a standard scumm SCAL block."
  },{}
};

static scc_param_help_t boxedit_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t boxedit_help = {
  .name = "boxedit",
  .usage = "[OPTIONS] file.box",
  .param_help = boxedit_param_help
};
