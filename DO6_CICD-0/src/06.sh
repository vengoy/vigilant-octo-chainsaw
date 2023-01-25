#!/bin/bash

TIME="10"
TELEGRAM_BOT_TOKEN="5907819678:AAHc3xQforo51f6Mi152NEyD-pric_jWZxI"
TELEGRAM_USER_ID="1301237686"
URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT="ID_pileline:+#$CI_PIPELINE_ID %0Astage:+$CI_JOB_STAGE %0Aname:+$CI_JOB_NAME %0Astatus:+$CI_JOB_STATUS %0AProject:+$CI_PROJECT_NAMEBranch:+$CI_COMMIT_REF_SLUG"

curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL >/dev/null
