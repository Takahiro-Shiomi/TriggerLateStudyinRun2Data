#!/bin/sh
cp ../build/test/TriggerLateStudy.out .

INPUT_NTUPLE="/gpfs/fs7001/shiomi/ATLAS/Physics/Bmumu/Data/data/CW_Data_Thre_BE_0805.root"
PDF_LABEL="TriggerLateStudy_Bsmumu_0806_Run2Data_3sta_pt11_ALLEvent"

echo ""
echo "PDF_LABEL: "${PDF_LABEL}
echo "INPUT_NTUPLE: "${INPUT_NTUPLE}
echo ""

COMMAND="./TriggerLateStudy.out ${INPUT_NTUPLE} ${PDF_LABEL}"

eval ${COMMAND} 2>&1

#eof
